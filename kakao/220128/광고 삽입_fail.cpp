// https://programmers.co.kr/learn/courses/30/lessons/72414
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long LL;

int vid_len;    //  동영상 길이(초)
int adv_len;    //  광고 길이(초)
LL aud_sum[360000] = {0, };            //  각 시각에 시청하고 있는 시청자 수
LL acc_sum[360000] = {0, };            //  각 시각 별 시청자 누적합
// vector<pair<int, int> > aud_logs;    //  시청자 시청 기록
vector<int> aud_logs;                   //  시청자 시청 기록(시청 시작 시각만 저장)
int max_start;
LL max_aud = -1;    //  최대 시청자 수

int part_sum(int start, int end) {  //  [start, end] 시간대의 시청자 수 합
    if(start == 0)
        return acc_sum[end];
    else
        return acc_sum[end] - acc_sum[start - 1];
}

int time_to_sec(string time) {  //  HH:MM:SS 꼴 문자열을 초 단위로 바꾸어 반환  
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));

    return h * 3600 + m * 60 + s;
}

string sec_to_time(int sec) {
    string ret = "";
    int h = sec / 3600;
    int m = (sec % 3600) / 60;
    int s = (sec % 3600) % 60;
    
    if(h < 10)
        ret += ("0" + to_string(h));
    else
        ret += to_string(h);
    ret += ":";
    if(m < 10)
        ret += ("0" + to_string(m));
     else
        ret += to_string(m);
    ret += ":";
    if(s < 10)
        ret += ("0" + to_string(s));
    else
        ret += to_string(s);

    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vid_len = time_to_sec(play_time);
    adv_len = time_to_sec(adv_time);

    if(vid_len == adv_len)     //  광고 시간이 전체 동영상 시간과 같을 경우
        return "00:00:00";     //  광고는 동영상과 동시에 시작되어야 함
    
    for(int i = 0; i < logs.size(); i++) {
        int start = time_to_sec(logs[i].substr(0, 8));
        int end = time_to_sec(logs[i].substr(9, 8));
        // aud_logs.push_back(make_pair(start, end));
        aud_logs.push_back(start);

        for(int j = start; j <= end; j++)
            aud_sum[j] += 1;
    }
    sort(aud_logs.begin(), aud_logs.end());

    acc_sum[0] = aud_sum[0];
    for(int i = 1; i <= vid_len; i++)
        acc_sum[i] = acc_sum[i - 1] + aud_sum[i];

    for(int i = 0; i < aud_logs.size(); i++) {
        int start = aud_logs[i];    //  시청 시작 시각에 광고 동시 시작
        int end = start + adv_len;  //  광고 종료 시각
        LL tmp;
        
        if(end > vid_len) continue; //  광고가 동영상 끝나는 시각보다 늦게 끝날 경우 배치 불가

        tmp = part_sum(start, end);
        if(tmp > max_aud) {
            max_aud = tmp;
            max_start = start;
            answer = sec_to_time(start);
        }
    }

    // cout << "최대 시청자 확보 가능 시각(초) : " << max_start << "\n";
    // cout << "최대 시청자 확보 가능 시각(HH:MM:SS) : " << answer << "\n";

    return answer;
}