// https://programmers.co.kr/learn/courses/30/lessons/64064?language=cpp
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> hash_map;

bool id_match(string banned_id, string user_id) {   //  user_id가 banned_id일 수 있나 확인
    bool ret = true;

    if(banned_id.length() != user_id.length())  //  길이가 다를 경우 절대 될 수 없음
        ret = false;
    else {  //  길이가 같을 경우 *을 제외한 부분이 같나 확인
        for(int i = 0; i < banned_id.length(); i++) {
            if(banned_id[i] != '*' && banned_id[i] != user_id[i]) {
                ret = false;
                break;
            }
        }
    }

    return ret;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<string> > result;
    vector<int> user_num;
    int r = banned_id.size();

    for(int i = 0; i < user_id.size(); i++)
        user_num.push_back(i);

    do {
        vector<string> tmp;
        bool is_ok = true;

        for(int i = 0; i < r; i++) {
            if(!id_match(banned_id[i], user_id[user_num[i]])) {
                is_ok = false;
                break;
            }
            tmp.push_back(user_id[user_num[i]]);
        }
        if(is_ok)
            result.push_back(tmp);

        reverse(user_num.begin() + r, user_num.end());
    } while(next_permutation(user_num.begin(), user_num.end()));

    for(int i = 0; i < result.size(); i++)
        sort(result[i].begin(), result[i].end());

    for(int i = 0; i < result.size(); i++) {
        string tmp = "";
        for(int j = 0; j < result[i].size(); j++)
            tmp += result[i][j];
        
        hash_map[tmp] = 1;
    }
    
    return hash_map.size();
}