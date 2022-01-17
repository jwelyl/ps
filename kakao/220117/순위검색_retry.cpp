// https://programmers.co.kr/learn/courses/30/lessons/72412
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
// #include <map>
#include <sstream>
#include <iostream>

using namespace std;

unordered_map<string, vector<int> > applicants;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for(int i = 0; i < info.size(); i++) {
        string tmp;
        stringstream ss(info[i]);
        vector<vector<string> > str;
        string key = "";
        int idx = 0, value;

        str.assign(4, vector<string>(2, "-"));
        
        while(ss >> tmp) {
            if(idx < 4)
                str[idx++][0] = tmp;
            else
                value = stoi(tmp);
        }

        for(int i1 = 0; i1 < 2; i1++) {
            for(int i2 = 0; i2 < 2; i2++) {
                for(int i3 = 0; i3 < 2; i3++) {
                    for(int i4 = 0; i4 < 2; i4++) {
                        key = str[0][i1] + str[1][i2] + str[2][i3] + str[3][i4];
                        // cout << "생성된 key : " << key << '\n';
                        applicants[key].push_back(value);
                    }
                }
            }       
        }

        // cout << "i = " << i <<'\n';
        // cout << "정렬 전\n";
        // for(int j = 0; j < applicants[key].size(); j++)
        //     cout << applicants[key][j] << " ";
        // cout << '\n';

        // sort(applicants[key].begin(), applicants[key].end());

        // cout << "정렬 후\n";
        // for(int j = 0; j < applicants[key].size(); j++)
        //     cout << applicants[key][j] << " ";
        // cout << "\n\n";
    }

    for(auto iter1 = applicants.begin(); iter1 != applicants.end(); iter1++)
        sort(iter1->second.begin(), iter1->second.end()); 


    for(int i = 0; i < query.size(); i++) {
        string tmp;
        stringstream ss(query[i]);
        string key = "";
        int idx = 0, target;
        int ans = 0;

        while(ss >> tmp) {
            // cout << "tmp = " << tmp << '\n';
            if(tmp != "and") {
                if(idx < 4) {
                    key += tmp;
                    idx++;
                }
                else
                    target = stoi(tmp);
            }
        }
        // cout << "완성된 조건 : " << key << '\n';
        // cout << "목표 점수 : " << target << '\n';

        // for(int j = 0; j < applicants[key].size(); j++) {
        //     if(target <= applicants[key][j])
        //         ans++;
        // }
        // answer.push_back(ans);
        
        vector<int>::iterator iter2 = lower_bound(applicants[key].begin(), applicants[key].end(), target);
        answer.push_back(applicants[key].size() - (iter2 - applicants[key].begin()));
    }

    return answer;
}