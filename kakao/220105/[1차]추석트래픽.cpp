#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define MS  1000

using namespace std;

vector<pair<int, int> > time_list;

int solution(vector<string> lines) {
    int answer = 0, tmp;
    int h, m, s, ms, p; //  각각 응답 완료된 시간, 분, 초, 처리 시간을 ms로 변환
    int start, end;

    for(int i = 0; i < lines.size(); i++) {
        lines[i].pop_back();    //  맨 끝의 s 제거

        h = stoi(lines[i].substr(11, 2)) * 3600 * MS;
        m = stoi(lines[i].substr(14, 2)) * 60 * MS;
        s = stoi(lines[i].substr(17, 2)) * MS;
        ms = stoi(lines[i].substr(20, 3));
        p = (int)(stod(lines[i].substr(24, -1)) * MS);

        end = h + m + s + ms;
        start = end - p + 1;    //  ex. 00:00:00.001 ~ 00:00:01.000은 999ms가 아니라 1000ms(1s)임

        time_list.push_back(make_pair(start, end));
    }

    for(int i = 0; i < time_list.size(); i++) {
        tmp = 0;

        for(int j = i; j < time_list.size(); j++) {
            if(time_list[i].second + 1000 > time_list[j].first)
                tmp++;
        }
        answer = max(answer, tmp);
    }

    return answer;
}