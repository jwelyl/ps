// https://programmers.co.kr/learn/courses/30/lessons/42890
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int n_tuples, n_attributes;
vector<int> idx;    //  attributes index
unordered_map<string, int> cand_key;

int solution(vector<vector<string> > relation) {
    int answer = 0;

    n_tuples = relation.size();
    n_attributes = relation[0].size();

    //  조합 구현을 위해 [0~attribute 개수 - 1] 저장
    for(int i = 0; i < n_attributes; i++)
        idx.push_back(i);

    //  n_attribute 개의 속성 중 i개를 뽑는 조합
	for(int i = 1; i <= n_attributes; i++) {
        vector<int> tmp;

        for(int j = 0; j < i; j++)
            tmp.push_back(1);
        for(int j = 0; j < n_attributes - i; j++)
            tmp.push_back(0);
        sort(tmp.begin(), tmp.end());

        // i개를 뽑는 조합 중 한 가지 경우
        do {
            vector<int> key_idx;    //  이번 조합에 포함된 attrubute idx
            unordered_map<string, int> tmp_map; //  이번 조합의 유일성 검사
            string key = "";
            bool is_key = true;

            for (int j = 0; j < tmp.size(); j++) {
                if (tmp[j] == 1)
                    key_idx.push_back(idx[j]);
            }

            // for(int l = 0; l < key_idx.size(); l++)
            //     cout << key_idx[l] << ' ';
            // cout << '\n';

            //  tuple 별로 해당 idx를 이용하여 중복 검사함
            for(int k = 0; k < n_tuples; k++) {
                key = "";   //  해당 idx의 attribute 값만 모아둔 문자열
                for(int l = 0; l < key_idx.size(); l++) {
                    key += relation[k][key_idx[l]];
                    key += "@"; //  구분자
                }

                // cout << "현재 tuple의 key : " << key << '\n';
                
                if(tmp_map.find(key) != tmp_map.end()) {    //  유일성 위배
                    // cout << "현재 tuple과 중복되는 tuple 존재
                    is_key = false;
                    break;
                }
                else
                    tmp_map[key] = 1;
            }

            if(is_key) {    //  유일성이 만족된 경우
                bool is_cand_key = true;    //  최소성 검사
                string key2 = "";
                for(int l = 0; l < key_idx.size(); l++) {
                    key2 += to_string(key_idx[l]);
                    key2 += "@";
                    if(cand_key.find(key2) != cand_key.end()) {  //  최소성을 위반할 경우
                        is_cand_key = false;
                        break;
                    }
                }

                if(is_cand_key) {
                    // cout << key2 << "를 후보키로 결정!\n";
                    cand_key[key2] = 1;
                }
            }
        } while(next_permutation(tmp.begin(), tmp.end()));
        // cout << "에헴2\n";
    }

    answer = cand_key.size();
    return answer;
}