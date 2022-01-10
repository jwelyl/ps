// https://programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int n;
vector<string> sets;                   //   집합들을 분리하여 저장
vector<vector<int> > int_sets;         //   각 집합들을 정수로 분리하여 저장
unordered_map<int, int> in_tuple;      //   answer에 원소가 이미 들어있는지 확인하기 위한 map

bool comp(string s1, string s2) {   //  집합 크기 순으로 오름차순 정렬
    return s1.size() < s2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    string tmp = "";    //  임시 문자열
    bool push = false;  //  true일 경우 삽입

    s.pop_back();
    s = s.substr(1, -1);    //  입력 문자열의 앞뒤 {, } 제거
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '{')             //  집합 시작 {
            push = true;            //  } 나타날 때까지 tmp에 삽입

        else if(s[i] == '}') {      //  집합 끝 }
            push = false;           //  삽입 중지
            sets.push_back(tmp);    //  집합 tmp를 sets에 삽입
            tmp = "";               //  tmp 초기화  
        }
        else {
            if(push == true)          
                tmp.push_back(s[i]);
        }
    }

    n = sets.size();    //  집합의 원소 개수

    sort(sets.begin(), sets.end(), comp);   //  sets의 원소들을 크기(집합의 원소 개수)로 오름차순 정렬

    int_sets.assign(n, vector<int>());      //  집합을 정수 집합으로 변환하기 위한 초기화

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= sets[i].size(); j++) {
            if(sets[i][j] == ',' || j == sets[i].size()) {  //  , 또는 끝에 도달할 경우
                int_sets[i].push_back(stoi(tmp));           //  tmp를 정수로 변환하여 삽입
                tmp = "";
                continue;
            }
            else 
                tmp.push_back(sets[i][j]);                  //  tmp에 삽
        }
    }

    for(int i = 0; i < int_sets.size(); i++) {
        for(int j = 0; j < int_sets[i].size(); j++) {
            if(in_tuple.find(int_sets[i][j]) == in_tuple.end()) {   //  answer에 해당 정수가 존재하지 않을경우
                in_tuple[int_sets[i][j]] = 1;                       //  삽입(존재) 표시
                answer.push_back(int_sets[i][j]);                   //  answer에 삽입
                continue;
            }
        }
    }

    return answer;
}