//  https://programmers.co.kr/learn/courses/30/lessons/17684
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int num = 1;
unordered_map<string, int> dict;

void init_dict() {  //  dictation 초기화 A=1, B=2, ... , Z=26
    char c = 'A';
    for(int i = 0; i < 26; i++) {
        string tmp = "";
        dict[tmp.insert(0, 1, c)] = num++;
        c += 1;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    
    init_dict();

    while(msg.size() > 0) {
        string w = "", c = "";

        for(int i = 0; i < msg.size(); i++) {
            if(dict[w + msg[i]] != 0)   //  dict에 존재하는 최대 길이의 w를 찾음
                w = w + msg[i];
            else break;
        }

        answer.push_back(dict[w]);  //  w의 number를 출력
        if(w.size() < msg.size())   //  다음 문자가 있을 경우
            c = msg[w.size()];      

        msg = msg.substr(w.size(), msg.size() - w.size());  //  msg에서 w를 제거
        dict[w + c] = num++;    //  w+c를 dict에 추가
    }

    return answer;
}