// https://programmers.co.kr/learn/courses/30/lessons/17678
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<int> bus;        //  각 버스에 태울 crew 수
vector<int> bus_time;   //  각 버스가 정류장에 도착하는 시각(분 단위)
vector<int> crew_time;  //  각 crew가 버스 정류장에 도착한 시각(분 단위)
queue<int> crew_q;     //  위의 vector를 편의상 queue로 바꿈

int time_to_min(string str) {   //  HH:MM 꼴 문자열을 분 단위 시간 정수로 바꿈
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}

string min_to_time(int minute) { //  분 단위 시간 minute을 HH:MM 꼴로 바꿈
    int HH = minute / 60;
    int MM = minute % 60;
    string ret = "";

    if(HH < 10)
        ret += ("0" + to_string(HH) + ":");
    else
        ret += (to_string(HH) + ":");
    
    if(MM < 10)
        ret += ("0" + to_string(MM));
    else
        ret += to_string(MM);

    return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    bus.assign(n, 0);

    for(int i = 0; i < n; i++) 
        bus_time.push_back(540 + t * i);
    for(int i = 0; i < timetable.size(); i++)
        crew_time.push_back(time_to_min(timetable[i]));
    sort(crew_time.begin(), crew_time.end());
    for(int i = 0; i < crew_time.size(); i++)
        crew_q.push(crew_time[i]);

    int idx = 0;
    while(!crew_q.empty()) {
        int t = crew_q.front();

        if(bus_time[idx] >= t && bus[idx] < m) {
            bus[idx] += 1;
            crew_q.pop();
        }
        else
            idx++;
    }

    int result = 0;
    idx = 0;    
    for(int i = 0; i < n; i++) {    //  i번째 bus 조사
        if(bus[i] < m)     //  해당 bus에 자리가 남을 경우
            result = max(result, bus_time[i]);
        else {  //  딱 m명 탄 경우
            vector<int> tmp;    //  i번째 bus 타는 사람들의 시간 저장 벡터
            for(int j = idx; j < idx + bus[i]; j++)
                tmp.push_back(crew_time[j]);
            result = max(result, tmp[m - 1] - 1);  //  i번째 bus에 마지막으로 탄 사람이 탄 시간
        }

        idx += bus[i];
    }

    answer = min_to_time(result);
    return answer;
}