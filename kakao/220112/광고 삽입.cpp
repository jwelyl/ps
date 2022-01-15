// https://programmers.co.kr/learn/courses/30/lessons/72414
#include <string>
#include <vector>
// #include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

int start_time = 0, end_time;
int adv_len;
int ans_start, ans_end;

// vector<pair<int, int> > log;
vector<int> viewers;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    end_time = stoi(play_time.substr(0, 2)) * 3600 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));
    adv_len = stoi(adv_time.substr(0, 2)) * 3600 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));
    viewers.assign(end_time + 1, 0);

    for(int i = 0; i < logs.size(); i++) {
        int s = stoi(logs[i].substr(0, 2)) * 3600 + stoi(logs[i].substr(3, 2)) * 60 + stoi(logs[i].substr(6, 2));
        int e = stoi(logs[i].substr(9, 2)) * 3600 + stoi(logs[i].substr(12, 2)) * 60 + stoi(logs[i].substr(15, 2));

        // log.push_back(make_pair(s, e));
        for(int j = s; j <= e; j++)
            viewers[j] += 1;
    }

    for(int i = 0; i < viewers.size(); i++) {
        int tmp_start, tmp_end;

        if(viewers[i] > 0) {
            tmp_start = i;
        }


    }

    // for(int i = 0; i < log.size(); i++) {
    //     cout << "(" << log[i].first << ", " << log[i].second << ")\n";
    // }



    return answer;
}