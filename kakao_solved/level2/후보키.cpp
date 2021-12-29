// https://programmers.co.kr/learn/courses/30/lessons/42890
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string> > relation) {
    int row = relation.size();
    int col = relation[0].size();
    vector<int> cols;   //  후보키들 모음

    //  ex) 속성 a, b, c 
    //  [c] = 001, [b] = 010, [b, c] = 011, [a] = 100, [a, c] = 101, [a, b] = 110, [a, b, c] = 111

    for(int i = 1; i < (1 << col); i++) {   //  i가 후보키가 됨(가능 키 개수 = 2^col - 1개)
        unordered_map<string, int> hash_map;

        for(int j = 0; j < row; j++) {  //  모든 행에 대하여
            string tmp = "";    

            for(int k = 0; k < col; k++) {  //  모든 열들 중
                if(i & (1 << k))    //  현재 열의 속성이 키에 포함될 경우
                    tmp += relation[j][k];  //  문자열에 더함
            }
            if(hash_map.find(tmp) == hash_map.end())    //  새로운 문자열일 경우(식별될 경우)
                hash_map[tmp] = 1;  //  hash_map에 추가
        }

        if(hash_map.size() == row) {    //  hash_map의 개수가 행의 개수와 같을 경우(모든 행이 유일하게 식별될 경우)
            bool is_key = true;    //  i가 새로운 후보키가 될 수 있는지
            for(int j = 0; j < cols.size(); j++) {
                if((cols[j] & i) == cols[j]) {  //  현재 키에 이미 후보키인 것이 포함될 경우
                    is_key = false;
                    break;
                }
            }
            if(is_key) cols.push_back(i);
        }
    }

    return cols.size();
}