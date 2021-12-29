// https://programmers.co.kr/learn/courses/30/lessons/64062
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_stones(vector<int> stones, int k) {  //  연속하여 0인 돌의 개수가 k개 미만인지 확인
    int zero_start = -1;    //  연속되는 0이 시작되는 위치
    int cnt = 0;            //  연속되는 0의 개수
    bool ret = true;        //  k개 미만일 경우 건너뛸 수 있으므로 true, k개 이상일 경우 

    for(int i = 0; i < stones.size(); i++) {
        if(stones[i] == 0 && zero_start == -1) {  //  처음 0이 나타났을 경우
            zero_start = i;
            cnt++;
        }
        else if(zero_start != -1 && stones[i] == 0) {   //  0이 계속될 경우
            cnt++;
            if(i == stones.size() - 1) {
                if(cnt >= k) {      //  연속해서 0이 되는 개수가 k 이상일 경우 
                ret = false;    //  건너 뛸 수 없으므로 건널 수 없음
                break;
                }
            }
        }
        else if(zero_start != -1 && stones[i] > 0) {  //  연속되는 0이 끝났을 경우
            if(cnt >= k) {      //  연속해서 0이 되는 개수가 k 이상일 경우 
                ret = false;    //  건너 뛸 수 없으므로 건널 수 없음
                break;
            }
            zero_start = -1;    //  연속 0의 개수가 k 이하인 경우 다음 0을 찾기 위해 초기화
            cnt = 0;
        }
    }

    return ret;
}

int binary_search(vector<int> stones, int k) {
    int start = 1;                  //  최소 1명은 건널 수 있음
    int end = *max_element(stones.begin(), stones.end());            //  최대 2억명 건널 수 있음
    int mid = (start + end) / 2;    //  mid명이 지날 수 있는 지 확인
    int ret = 0;   

    while(start <= end) {   //  mid
        vector<int> tmp(stones);

        for(int i = 0; i < tmp.size(); i++) {   //  mid - 1 명이 건넌 상태 만들기
            if(tmp[i] >= mid - 1) tmp[i] -= (mid - 1);
            else tmp[i] = 0;
        }

        if(!check_stones(tmp, k)) { //  mid명이 건널 수 없을 경우
            end = mid - 1;
            mid = (start + end) / 2;
        }
        else {  //  mid명이 건널 수 있을 경우 더 많은 수가 건널 수 있나 확인
            ret = max(ret, mid);
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }

    return ret;
}

int solution(vector<int> stones, int k) {
    int answer = binary_search(stones, k);
    return answer;
}