// https://programmers.co.kr/learn/courses/30/lessons/17676
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> arr;
vector<pair<int, int> > log;

int time_to_ms(string t) {  //  hh:mm:ss.sss 꼴 문자열을 ms 단위 정수로 변환
    double h = stod(t.substr(0, 2));
    double m = stod(t.substr(3, 2));
    double s = stod(t.substr(6));

    return (int)((h * 3600 + m * 60 + s) * 1000);
}

int solution(vector<string> lines) {
    int answer = 0;
    // string max_time = "24:00:00";
    // int size = time_to_ms(max_time);
    // arr.assign(size, 0);
    // cout << "size = " << size << '\n';

    for(int i = 0; i < lines.size(); i++) {
        string ctime = lines[i].substr(11, 12);  //  응답 완료 시간
        string ptime = lines[i].substr(24);         //  처리 시간
        int start = 0, end = 0;
        ptime.pop_back();   //  마지막 's' 제거

        end = time_to_ms(ctime);
        start = end - (int)(stod(ptime) * 1000) + 1;
        if(start < 0) start = 0;

        log.push_back(make_pair(start, end));
    }

    for(int i = 0; i < log.size(); i++) {
        int tmp = 0;

        for(int j = i; j < log.size(); j++) {
            if(log[i].second + 1000 > log[j].first)
                tmp++;
        }

        answer = max(answer, tmp);
    }

    return answer;
}