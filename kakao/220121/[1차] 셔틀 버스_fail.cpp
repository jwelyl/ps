// https://programmers.co.kr/learn/courses/30/lessons/17678
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int idx;
int last_time;                      //  막차 도착시간
const int BUS_START = 540;          //  09:00 (540분)
vector<int> bus_time;               //  버스가 도착하는 시간
vector<int> crew_time;              //  crew가 도착하는 시간
vector<int> time_arr(60 * 24, 0);   //  각 시각(분)에 도착한 crew 수
vector<int> sum_arr(60 * 24, 0);    //  특정 분까지 도착한 crew 수 누적합

int time_to_min(string time) {  //  HH:MM 꼴 문자열을 분 단위 시간 정수로 바꿈
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int num_crews(int start, int end) { //  [start, end]에 도착한 crew 수
    if(start == 0)
        return sum_arr[end];
    else
        return sum_arr[end] - sum_arr[start - 1];
}

string min_to_time(int minute) {    //  분 단위 시간을 HH:MM 꼴 문자열로 변환함
    int h = minute / 60;
    int m = minute % 60;
    string HH = to_string(h);
    string MM = to_string(m);

    if(h / 10 == 0)
        HH = "0" + HH;
    if(m / 10 == 0)
        MM = "0" + MM;

    return HH + ":" + MM;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    bus_time.push_back(-1);              //  00:00
    bus_time.push_back(BUS_START);       //  09:00
    // cout << min_to_time(BUS_START) << '\n';

    for(int i = 1; i <= n - 1; i++)
        bus_time.push_back(BUS_START + t * i);
    last_time = bus_time.back();

    for(int i = 0; i < timetable.size(); i++) {
        int m = time_to_min(timetable[i]);
        crew_time.push_back(m);
        time_arr[m] += 1;
    }
    sort(crew_time.begin(), crew_time.end());   //  crew 도착 시간 순으로 정렬

    sum_arr[0] = time_arr[0];
    for(int i = 1; i < time_arr.size(); i++) {
        sum_arr[i] = sum_arr[i - 1] + time_arr[i];  //  누적합 구하기
    }

    // if(sum_arr[last_time] < m * n) {    //  막차 도착때까지 crew 수가 m * n 이하일 경우 막차를 타면 됨
    //     answer = min_to_time(last_time);
    // }
    // else if(sum_arr[last_time] == m * n) {
    //     for(int i = last_time - 1; )
    // }

    auto iter = lower_bound(sum_arr.begin(), sum_arr.begin() + last_time + 1, m * n);

    if(iter == sum_arr.begin() + last_time + 1)     //  막차를 타면 됨
        answer = min_to_time(last_time);
    else if(*iter >= m * n) {
        idx = iter - sum_arr.begin() - 1;
        answer = min_to_time(idx);
    }

    return answer;
}