// https://programmers.co.kr/learn/courses/30/lessons/64062
#include <string>
#include <vector>
#include <algorithm>
#define MAXNUM  200000000   //  최대 2억명 건널수 있음

using namespace std;

bool cross(int k, vector<int> arr) {   //  지금 상태에서 한 명이 다리를 건널 수 있나 파악(가능하면 true, 불가능하면 false)
    bool ret = true;
    int cur = -1;
    int end = arr.size();

    while(cur < end) {
        int j;
        for(j = cur + 1; j <= cur + k; j++) {
            if(j >= end || arr[j] > 0) {    //  도착했거나 디딜 돌을 발견한 경우
                cur = j;
                break;
            }
        }
        if(j == cur + k + 1) {  //  디딜 돌이 없는 경우
            ret = false;
            break;
        }
    }

    return ret;
}

int binary_search(int k, vector<int> stones) {
    int start = 1;  
    int end = MAXNUM;
    int mid = (start + end) / 2;
    int result = 1;

    while(start <= end) {
        vector<int> arr(stones);
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > mid - 1)  //  mid - 1명이 건넌 상태
                arr[i] -= (mid - 1);
            else arr[i] = 0;
        }

        if(cross(k, arr)) {    //  mid - 1명이 건넌 상태에서 1명이 더 건널 수 있나 확인, 더 건널 수 있을 경우 mid 증가
            start = mid + 1;
            result = max(result, mid);
        }
        else      //  mid명이 건널 수 없을 경우 더 적은 사람은 건널 수 있나 확인해야 함
            end = mid - 1;
        mid = (start + end) / 2;
    }

    return result;
}

int solution(vector<int> stones, int k) {
    int answer = binary_search(k, stones);

    return answer;
}