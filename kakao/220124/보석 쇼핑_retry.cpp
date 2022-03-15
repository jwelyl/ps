// https://programmers.co.kr/learn/courses/30/lessons/67258
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> gmap;    //  key : 보석 종류, value : 보석 개수
int n_type = 0;     //  보석의 종류 개수
int c_type = 0;     //  현재 장만한 보석의 종류 수(n_type과 같아지는 게 목표)

// bool comp(vector<int> v1, vector<int> v2) {
//     int d1 = v1[1] - v1[0];
//     int d2 = v2[1] - v2[0];

//     if(d1 < d2)
//         return true;
//     else if(d1 == d2) 
//         return v1[0] < v2[0];
//     else return false;
// }

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    // vector<vector<int> > cands; //  정답 후보
    int start = 0, end = 0;

    answer[0] = 1;
    answer[1] = 100001;
    
    for(int i = 0; i < gems.size(); i++) 
        gmap[gems[i]] += 1;
    n_type = gmap.size();

    unordered_map<string, int>().swap(gmap);

    while(start < gems.size() && end < gems.size()) {
        vector<int> cand(2, 0);

        if(c_type < n_type) {   //  현재 구매한 보석 종류가 부족할 경우 end의 보석 하나 추가
            if(gmap.find(gems[end]) == gmap.end()) 
                c_type += 1;
            gmap[gems[end]] += 1;
        }
        
        if(c_type == n_type) {  //  보석이 충분할 경우 현재 start에서 보석 하나 제거
            cand[0] = start + 1, cand[1] = end + 1;
            
            if(cand[1] - cand[0] < answer[1] - answer[0])
                cand.swap(answer);
            else if(cand[1] - cand[0] == answer[1] - answer[0] && cand[0] < answer[0])
                cand.swap(answer);
                

            if(gmap[gems[start]] == 1) {    //  그 종류의 유일한 보석일 경우
                gmap[gems[start]] = 0;
                gmap.erase(gems[start]);
                c_type -= 1;
            }
            else gmap[gems[start]] -= 1;

            start++;
            if(start > end)    //  만약 이전 구간 길이가 1이었으면 end도 이동해야 함
                end++;
        }
        else 
            end++;
    }

    // sort(cands.begin(), cands.end(), comp);
    // for(int i = 0; i < cands.size(); i++) 
    //     cout << "[" << cands[i][0] << ", " << cands[i][1] << "], ";
    // cout << '\n';
    // answer = cands[0];

    return answer;
}