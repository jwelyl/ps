// https://programmers.co.kr/learn/courses/30/lessons/17686
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

vector<pair<string, pair<string, string> > > tmp;

bool comp(pair<string, pair<string, string> > s1, pair<string, pair<string, string> > s2) {
    const char* head1 = s1.first.c_str();
    const char* head2 = s2.first.c_str();
    int num1 = 0;
    int num2 = 0;

    if(strcasecmp(head1, head2) != 0)    //  head로 비교가 끝나는 경우
        return (strcasecmp(head1, head2) < 0);
    else {
        int mul = 1;

        for(int i = s1.second.first.length() - 1; i >= 0; i--) {
            num1 += (s1.second.first[i] - '0') * mul;
            mul *= 10;
        }
        mul = 1;
        for(int i = s2.second.first.length() - 1; i >= 0; i--) {
            num2 += (s2.second.first[i] - '0') * mul;
            mul *= 10;
        }

        if(num1 != num2)
            return (num1 < num2);
        else return false;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    bool num5 = true;

    for(int i = 0; i < files.size(); i++) {
        string head = "", number = "", tail = "";
        int ns, ne, ts = -1;
        num5 = true;

        for(int j = 0; j < files[i].size(); j++) {
            if('0' <= files[i][j] && files[i][j] <= '9') {
                ns = j;
                break;
            }
        }

        head += files[i].substr(0, ns);
        // cout << "head : " << head << '\n';

        for(int j = ns; j < ns + 5; j++) {
            if(j == files[i].length() - 1) {    //  tail 없이 file명 끝나는 경우
                ne = j;
                num5 = false;
                break;
            }
            else if(!('0' <= files[i][j] && files[i][j] <= '9')) {  //  number 5자리 안될 경우
                ne = j - 1;
                ts = j;
                num5 = false;
                break;
            }
        }
        if(num5) {
            ne = ns + 4;
            ts = (ne + 1 <= files[i].length() - 1) ? ne + 1 : -1;
        }

        number += files[i].substr(ns, ne - ns + 1);

        if(ts != -1)
            tail += files[i].substr(ts, files[i].npos);

        tmp.push_back(make_pair(head, make_pair(number, tail)));
    }

    sort(tmp.begin(), tmp.end(), comp);

    for(int i = 0; i < tmp.size(); i++) {
        string temp;
        
        temp = tmp[i].first;
        temp += tmp[i].second.first;
        temp += tmp[i].second.second;
        answer.push_back(temp);
    }

    return answer;
}