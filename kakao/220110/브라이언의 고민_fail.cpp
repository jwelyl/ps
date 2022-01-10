//  https://programmers.co.kr/learn/courses/30/lessons/1830
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<char, int> sch_map;   //  특수 문자 map
vector<char> sch;   //  특수 문자
vector<int> space;  //  공백 삽입할 위치

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";

    for(int i = 0; i < sentence.size(); i++) {
        if('a' <= sentence[i] && sentence[i] <= 'z') {
            if(sch_map.find(sentence[i]) == sch_map.end()) {
                sch_map[sentence[i]] = 1;
                sch.push_back(sentence[i]);
            }
        }
    }

    cout << "sch\n";
    for(int i = 0; i < sch.size(); i++)
        cout << sch[i] << "\n";
    return answer;
}