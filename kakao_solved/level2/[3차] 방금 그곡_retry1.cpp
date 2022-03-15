// https://programmers.co.kr/learn/courses/30/lessons/17683
#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

unordered_map<string, char> notes;

int time_to_min(string t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

string convert(string original) {
    string ret = "";

    for(int i = 0; i < original.size(); i++) {
        string note = "";

        if(original[i] != '#') {
            note = original[i];
            if(i + 1 < original.size()) {
                if(original[i + 1] == '#') {
                    note += original[i + 1];
                    note = notes[note];
                }
            }
            ret += note;
        }
        else continue;
    }

    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int answer_len = -1;

    notes["C#"] = 'V';
    notes["D#"] = 'W';
    notes["F$"] = 'X';
    notes["G#"] = 'Y';
    notes["A#"] = 'Z';

    // cout << "before converting : " << m << "(" << m.size() << ")\n";
    m = convert(m); //  들은 부분 변환함
    // cout << "after converting : " << m << "(" << m.size() << ")\n";

    for(int i = 0; i < musicinfos.size(); i++) {
        int s_time = time_to_min(musicinfos[i].substr(0, 5));
        int e_time = time_to_min(musicinfos[i].substr(6, 5));
        int len = e_time - s_time;  //  음악 재생 길이
        string title = "";  //  제목
        string music = "";  //  악보
        string played = ""; //  방송된 음악
        int idx = 12, q, r;

        for(; idx < musicinfos[i].size(); idx++) {
            if(musicinfos[i][idx] == ',')
                break;
            title.push_back(musicinfos[i][idx]);
        }
        music = musicinfos[i].substr(idx + 1);
        music = convert(music); //  악보를 변환함

        q = len / music.size();
        r = len % music.size();

        for(int i = 0; i < q; i++)
            played += music;
        played += music.substr(0, r);

        // cout <<"played music (" << i << ") " << title << " : " << played << '\n';

        if(played.find(m) != played.npos) {
            if(answer_len < len) {
                answer_len = len;
                answer = title;
            }
        }
    }

    return answer;
}