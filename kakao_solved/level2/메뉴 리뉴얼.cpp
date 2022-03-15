// https://programmers.co.kr/learn/courses/30/lessons/72411
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <cstring>
#include <iostream>

using namespace std;

unordered_map<string, int> menu;
unordered_map<int, int> menu_size;
vector<pair<string, int> > v;

bool comp(pair<string, int> p1, pair<string, int> p2) {
    if(p1.first.size() != p2.first.size())
        return p1.first.size() < p2.first.size();
    else 
        return p1.second > p2.second;
}  

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i = 0; i < orders.size(); i++) {
        //  i번째 손님 주문
        // cout << i << "번째 손님이 주문한 음식에서 코스 경우의 수\n";
        // if(orders[i].size() < 2) continue;

        sort(orders[i].begin(), orders[i].end());

        for(int j = 0; j < course.size(); j++) {
            menu_size[course[j]] = 1;

            if(course[j] > orders[i].size())    //  코스에 필요한 요리 가짓수가 주문된 요리 개수보다 많은 경우
                continue;
            // cout << "길이 " << course[j] << "인 코스\n";
        
            vector<bool> tmp(orders[i].size(), true);
            for(int k = 0; k < course[j]; k++)
                tmp[k] = false;

            do {
                string str = "";
                for(int k = 0; k < tmp.size(); k++) {
                    if(tmp[k] == false)
                        str.push_back(orders[i][k]);
                }
                menu[str] += 1;
                // cout << str << '\n';

            } while(next_permutation(tmp.begin(), tmp.end()));
        }
    }

    for(auto m : menu) 
        // cout << m.first << ", " << m.second << '\n';
        v.push_back(make_pair(m.first, m.second));
    
    sort(v.begin(), v.end(), comp);

    // for(int i = 0; i < v.size(); i++) {
    //     cout << "{" << v[i].first << " : " << v[i].second << "} ";
    // }
    // cout << '\n';

    int menu_len = v[0].first.size();
    int menu_cnt = v[0].second;

    for(int i = 0; i < v.size(); i++) {
        int menu_cur_len = v[i].first.size();
        int menu_cur_cnt = v[i].second;

        if(menu_cur_len == menu_len && menu_cur_cnt == menu_cnt)
            answer.push_back(v[i].first);
        else if(menu_cur_len > menu_len && menu_cur_cnt > 1) {
            answer.push_back(v[i].first);
            menu_len = menu_cur_len;
            menu_cnt = menu_cur_cnt;
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}