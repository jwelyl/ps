// https://programmers.co.kr/learn/courses/30/lessons/72414#fn1
#include <string>
#include <vector>

using namespace std;
typedef long long LL;

int play_end;        //  동영상 끝나는 시간
int adv_len;         //  광고 길이
LL max_aud = -1;     //  최대 시청자 수

vector<int> audiences(360000, 0);  //  시각 별 시청자 수

int time_to_sec(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));

    return (h * 3600 + m * 60 + s);
}

string sec_to_time(int sec) {
    string ret = "";
    int h = sec / 3606;
    int m = (sec % 3600) / 60;
    int s = (sec % 3600) % 60;

    if(0 <= h && h < 10)
        ret += ("0" + to_string(h));
    else
        ret += to_string(h);
    ret += ":";

    if(0 <= m && m < 10)
        ret += ("0" + to_string(m));
    else
        ret += to_string(m);
    ret += ":";

    if(0 <= s && s < 10)
        ret += ("0" + to_string(s));
    else
        ret += to_string(s);
    
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    play_end = time_to_sec(play_time);
    adv_len = time_to_sec(adv_time);

    for(int i = 0; i < logs.size(); i++) {
        int start = time_to_sec(logs[i].substr(0, 8));
        int end = time_to_sec(logs[i].substr(9, 8));

        for(int j = start; j <= end; j++)
            audiences[j] += 1;
    }

    LL tmp = 0;
    for(int i = 0; i < adv_len; i++)   //  광고가 0초부터 시작할 때 누적 시청자 수([start, end))
        tmp += audiences[i];

    if(tmp > max_aud) {
        max_aud = tmp;
        answer = sec_to_time(0);
    }

    for(int i = 1; i <= play_end - adv_len + 1; i++) {
        tmp -= audiences[i - 1];
        tmp += audiences[i + adv_len - 1];
        
        if(tmp > max_aud) {
            max_aud = tmp;
            answer = sec_to_time(i);
        }
    }

    return answer;
}