// https://programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, int> map;
vector<vector<int> > arr;

bool comp(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    string num = "";
    vector<int> tmp;

    for(int i = 2; i < s.length() - 1; i++) {
        if('0' <= s[i] && s[i] <= '9')
            num += s[i];
        else if(s[i] == ',') {
            if(num != "") {
                tmp.push_back(stoi(num));
                num = "";
            }
        }
        else if(s[i] == '}') {
            tmp.push_back(stoi(num));
            num = "";
        }
        else if(s[i] == '{') {
            arr.push_back(tmp);
            vector<int>().swap(tmp);
        }
    }
    arr.push_back(tmp);
    vector<int>().swap(tmp);
    sort(arr.begin(), arr.end(), comp);
    // for(int i = 0; i < arr.size(); i++) {
    //     cout << "[";
    //     for(int j = 0; j < arr[i].size(); j++)
    //         cout << arr[i][j] << ",";
    //     cout << "]\n";
    // }

    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            if(map.find(arr[i][j]) == map.end()) {
                map[arr[i][j]] = 1;
                answer.push_back(arr[i][j]);
            }
        }
    }

    return answer;
}

// int main(void) {
//     vector<int> answer = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");

//     for(int i = 0; i < answer.size(); i++)
//         cout << answer[i] << ' ';
//     cout << '\n';
    
//     return 0;
// }