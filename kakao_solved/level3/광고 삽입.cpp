// https://programmers.co.kr/learn/courses/30/lessons/72414
#include <string>
#include <vector>
#include <utility>

#include <iostream>

using namespace std;

vector<long long> viewers;        //  각 초별 시청자 수

int string_to_second(string str_time) { //  문자열로 된 시각 또는 시간을 초로 변경
    int ret = stoi(str_time.substr(6, str_time.npos));
    ret += stoi(str_time.substr(3, 2)) * 60;
    ret += stoi(str_time.substr(0, 2)) * 3600; 

    return ret;
}

string second_to_string_time(int second) {
    string ret = "";
    int h, m, s;

    h = second / 3600;
    second = second % 3600;
    m = second / 60;
    second = second % 60;
    s = second;

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

    int play_end = string_to_second(play_time);
    int adv_length = string_to_second(adv_time);
    int start = 0;
    long long sum = 0, tmp = 0;
    viewers.assign(play_end + 1, 0);

    for(int i = 0; i < logs.size(); i++) {
        int view_num = i + 1;
        int view_start = string_to_second(logs[i].substr(0, 8));    //  시청 시작 시간
        int view_end = string_to_second(logs[i].substr(9, 8));      //  시청 완료 시간

        for(int j = view_start; j < view_end; j++)
            viewers[j] += 1;
    }

    for(int i = 0; i < adv_length; i++)    //  0초부터 (adv_length - 1)초까지 시청자 수 합 구하기
        tmp += viewers[i];
    if(sum < tmp) {
        sum = tmp;
        start = 0;
    }

    for(int i = 1; i <= play_end - adv_length; i++) {
        tmp -= viewers[i - 1];
        tmp += viewers[i + adv_length - 1];

        if(sum < tmp) {
            sum = tmp;
            start = i;
        }
    }

    answer = second_to_string_time(start);

    return answer;
}