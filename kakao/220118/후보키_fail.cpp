// https://programmers.co.kr/learn/courses/30/lessons/42890
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> tuple_map;
vector<int> prev_keys;


int n_row;  //  튜플 개수
int n_col;  //  속성 개수

int solution(vector<vector<string> > relation) {
    int answer = 0;
    n_row = relation.size();
    n_col = relation[0].size();

    for(int i = 1; i < (1 << n_col); i++) {
        vector<int> key_idx;
        int cur_key = i;
        int idx = 0;
        bool dup_success = true;    //  유일성 검사
        bool min_success = true;    //  최소성 검사
        string key;

        while(cur_key > 0) {
            if(cur_key % 2 == 1)
                key_idx.push_back(idx);
            cur_key /= 2;
            idx++;
        }
        for(int j = 0; j < key_idx.size(); j++)
            cout << key_idx[j] << " ";
        cout << '\n';

        unordered_map<string, int> tmp; 
        for(int j = 0; j < n_row; j++) {
            key = "";
            for(int k = 0; k < key_idx.size(); k++) {
                key += relation[j][key_idx[k]];
                key += "@"; //  구분자
            }
            // cout << "(" << i << ") 현재 " << j << "행에서 완성된 key : " << key << '\n';
            tmp[key] += 1;
        }

        if(tmp.size() != n_row) {
            dup_success = false;
            break;
        }

        if(dup_success) {
            //  최소성 검사
            for(int j = 0; j < prev_keys.size(); j++) {
                if(prev_keys[j] & i == prev_keys[j]) { //  최소성 위반
                    min_success = false;
                    break;
                } 
            }

            if(min_success) {    //  중복성, 최소성 모두 만족
                answer += 1;
                // tuple_map[key] = 1; //  tuple_map에 삽입
                prev_keys.push_back(i);
            }
        }
    }

    return answer;
}