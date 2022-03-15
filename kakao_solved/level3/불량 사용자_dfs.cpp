// https://programmers.co.kr/learn/courses/30/lessons/64064
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

int n;
vector<bool> visited;
vector<int> banned_indices;
unordered_map<string, int> hashmap;

bool can_match(string user, string banned) {
    if(user.size() != banned.size())
        return false;
    
    for(int i = 0; i < banned.size(); i++) {
        if(banned[i] == '*')
            continue;
        else if(banned[i] != user[i])
            return false;
    }

    return true;
}

string indices_to_str(vector<string> user_id, vector<int> indices) {    //  사용자1@사용자2@...@ 꼴로 변환
    string ret = "";
    sort(indices.begin(), indices.end());

    for(int i = 0; i < indices.size(); i++)
        ret += (user_id[indices[i]] + "@");
    
    return ret;
}

void dfs(vector<string> user_id, vector<string> banned_id, int depth, int idx) {
    visited[idx] = true;
    banned_indices.push_back(idx);

    if(depth == n - 1) {
        hashmap[indices_to_str(user_id, banned_indices)] = 1;
        visited[idx] = false;
        banned_indices.pop_back();
        return;
    }

    string banned = banned_id[depth + 1];
    for(int i = 0; i < user_id.size(); i++) {
        if(!visited[i] && can_match(user_id[i], banned))
            dfs(user_id, banned_id, depth + 1, i);
    }

    visited[idx] = false;
    banned_indices.pop_back();
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    n = banned_id.size();
    visited.assign(user_id.size(), false);

    string banned = banned_id[0];
    for(int i = 0; i < user_id.size(); i++) {
        if(!visited[i] && can_match(user_id[i], banned))
            dfs(user_id, banned_id, 0, i);
    }
    
    answer = hashmap.size();

    return answer;
}