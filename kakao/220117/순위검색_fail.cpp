// https://programmers.co.kr/learn/courses/30/lessons/72412
#include <string>
#include <vector>
#include <utility>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string> > applicants, queries;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    applicants.assign(info.size(), vector<string>());
    queries.assign(query.size(), vector<string>());
    for(int i = 0; i < info.size(); i++) {
        int bs = 0;
        string str[5] = {"", "", "", "", ""};


        for(int j = 0; j < info[i].size(); j++) {
            if(info[i][j] == ' ') 
                bs++;
            else {
                str[bs].push_back(info[i][j]);  
            }
        }   
        for(int j = 0; j < 5; j++)
            applicants[i].push_back(str[j]);
    }

    for(int i = 0; i < query.size(); i++) {
        int bs = 0;
        bool is_and = false;
        string str[5] = {"", "", "", "", ""};

        for(int j = 0; j < query[i].size(); j++) {
            if(query[i][j] == ' ') {
                if(bs == 3) {
                    bs = 4;
                    continue;
                }

                if(is_and) {
                    is_and = false;
                    bs++;
                }
                else is_and = true;
            
            }
            else {
                if(!is_and)
                    str[bs].push_back(query[i][j]);
            } 
        }   
        for(int j = 0; j < 5; j++)
            queries[i].push_back(str[j]);
    }

    sort(applicants.begin(), applicants.end());

    for(int i = 0; i < queries.size(); i++) {
        int ans = 0;

        for(int j = 0; j < applicants.size(); j++) {
            bool cond = true;

            for(int k = 0; k < 4; k++) {
                if(queries[i][k] == "-")
                    continue;
                else if(queries[i][k] != applicants[j][k]) {
                    cond = false;
                    break;
                }
                else continue;
            }

            if(cond) {
                if(stoi(queries[i][4]) <= stoi(applicants[j][4]))
                    ans++;
            }
        }
        answer.push_back(ans);
    }

    return answer;
}

