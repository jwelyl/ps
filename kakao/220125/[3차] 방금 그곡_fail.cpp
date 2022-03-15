// https://programmers.co.kr/learn/courses/30/lessons/17683
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

#define CSH 'V'
#define DSH 'W'
#define FSH 'X'
#define GSH 'Y'
#define ASH 'Z'

using namespace std;

int time_to_min(string t) { //  HH:MM 시각 문자열을 분 단위 시각 정수로 바꿈
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

string convert(string before) { //  #이 포함된 음을 # 없는 동등한 음으로 변경
    string ret = "";

    if(before.size() <= 1)
        ret = before;
    else {
        for(int i = 0; i < before.size(); ) {
            if(before[i] != '#') {
                if(i + 1 < before.size()) {
                    if(before[i + 1] != '#') {
                        ret.push_back(before[i]);
                        i++;
                    }
                    else {
                        string tmp = before.substr(i, 2);
                        if(tmp == "C#")
                            ret.push_back(CSH);
                        else if(tmp == "D#")
                            ret.push_back(DSH);
                        else if(tmp == "F#")
                            ret.push_back(DSH);
                        else if(tmp == "G#")
                            ret.push_back(GSH);
                        else if(tmp == "A#")
                            ret.push_back(ASH);
                        i += 2;
                    }
                }
                else {
                    ret.push_back(before[i]);
                    i++;
                }
            }
        }
    }

    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "None";
    int ans_len = -1;
    string m_real = convert(m); //  ex C#은 하나의 다른 기호 H로 대치

    for(int i = 0; i < musicinfos.size(); i++) {
        int s = time_to_min(musicinfos[i].substr(0, 5));    //  음악 시작 시간(분)
        int e = time_to_min(musicinfos[i].substr(6, 5));    //  음악 끝나는 시간
        int q, r;               //  악보 반복 횟수 q, 추가로 1회 재생되던 시간 r(r분 후 끊김)
        string name = "";       //  노래 제목 
        string partial = "";    //  악보 정보
        string real = "";       //  악보 정보를 변환
        int len = abs(e - s);    //  음악 전체 길이
        int idx = 12;

        for(; idx < musicinfos[i].size(); idx++) {
            if(musicinfos[i][idx] == ',')
                break;
            else
                name.push_back(musicinfos[i][idx]);
        }
        partial = musicinfos[i].substr(idx + 1);

        partial = convert(partial); //  # 포함된 음을 # 없앤 동일한 음으로 변경
        q = len / partial.size();
        r = len % partial.size();

        for(int j = 0; j < q; j++)
            real += partial;
        real += partial.substr(0, r);

        if(real.find(m_real) != real.npos) {    //  멜로디가 포함될 경우
            if(len > ans_len) {
                ans_len = len;
                answer = name;
            }
        }
    }

    return answer;
}