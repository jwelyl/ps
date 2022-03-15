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

    int result = 0;
    for(int i = 0; i < bus_time.size() - 1; i++) {
        int start = bus_time[i] + 1;            //  직전 버스 도착 후 1분 뒤 (00:00부터 시작)
        int end = bus_time[i + 1];              //  다음에 올 버스 도착 시간
        int waiting = num_crews(start, end);    //  [start, end]에 와서 기다린 사람
        int tmp = -1;

        if(i >= 1) {    //  이전에 못 탄 사람들도 고려해야 함
            int wait_before = num_crews(0, start - 1);

            if(wait_before <= m * i) {   //  이전 버스를 기다리던 사람들이 모두 탔을 경우 현재 구간만 고려하면 됨
                if(waiting < m) 
                    tmp = end;
                else {
                    for(int j = end; j >= start; j--) {
                        if(num_crews(start, j) == m) {
                            tmp = j - 1;
                            break;
                        }
                        else if(num_crews(start, j) < m) {
                            tmp = j;
                            break;
                        }
                    }
                }
            }
            else {
                waiting += (wait_before - m * i);
                
                if(waiting < m) 
                    tmp = end;
                else {
                    for(int j = end; j >= start; j--) {
                        if(num_crews(start, j) == m) {
                            tmp = j - 1;
                            break;
                        }
                        else if(num_crews(start, j) < m) {
                            tmp = j;
                            break;
                        }
                    }
                }
            }
        }
        else {  //  [start, end]만 고려하면 됨
            if(waiting < m) //  기다리는 사람이 m명보다 적을 경우
                tmp = end;
            else {
                for(int j = end; j >= 0; j--) {
                    if(sum_arr[j] == m) {
                        tmp = j - 1;
                        break;
                    }
                    else if(sum_arr[j] < m) {
                        tmp = j;
                        break;
                    }
                }
            }
        }

        result = max(result, tmp);
    }

    answer = min_to_time(result);
    return answer;
}