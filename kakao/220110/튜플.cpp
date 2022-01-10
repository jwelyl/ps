// https://programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n;
vector<string> sets;
vector<vector<int> > int_sets;

bool comp(string s1, string s2) {
    return s1.size() < s2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    string tmp = "";
    bool push = false;

    s.pop_back();
    s = s.substr(1, -1);
    cout << s << '\n';
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '{') {
            push = true;
        }
        else if(s[i] == '}') {
            push = false;
            cout << "삽입할 집합 : " << tmp << "\n";
            sets.push_back(tmp);
            tmp = "";
        }
        else {
            if(push == true) {
                tmp.push_back(s[i]);
            }
        }
    }

    n = sets.size();

    sort(sets.begin(), sets.end(), comp);

    cout << "n : " << n << '\n';
    cout << "sets\n";
    for(int i = 0; i < sets.size(); i++) {
        cout << sets[i] << "\n";
    }

    int_sets.assign(n, vector<int>());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= sets[i].size(); j++) {
            if(sets[i][j] == ',' || j == sets[i].size()) {
                int_sets[i].push_back(stoi(tmp));
                tmp = "";
                continue;
            }
            else {
                tmp.push_back(sets[i][j]);
            }
        }
    }

    cout << "완성된 정수 배열\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < int_sets[i].size(); j++) {
            cout << int_sets[i][j] << " ";
        }
        cout << '\n';
    }

    return answer;
}