// https://programmers.co.kr/learn/courses/30/lessons/64062
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAXNUM  200000000   //  최대 2억명 건널수 있음

using namespace std;

void reset_arr(vector<int> stones, vector<int>& arr) {
    arr.resize(stones.size());
    copy(stones.begin(), stones.end(), arr.begin());
}

bool cross(int n, int k, vector<int>& arr) {   //  n명이 다리를 건널 수 있나 파악(가능하면 true, 불가능하면 false)
    bool ret = true;

    for(int i = 0; i < n; i++) {    //  n명이 모두 건널수 있나 확인
        int start = -1;             //  출발점
        int end = arr.size();       //  도착점
        int cur = start;            //  현재 위치

        while(cur < end) {
            int j;
            for(j = cur + 1; j <= cur + k; j++) {
                if(j >= end) {
                    cur = j;
                    break;
                }
                else if(arr[j] > 0) {
                    cur = j;
                    arr[j] -= 1;
                    break;
                }
            }
            if(j == cur + k + 1) {
                ret = false;
                break;
            }
        }
        if(!ret) break;
    }

    return ret;
}

int binary_search(int k, vector<int> stones, vector<int>& arr) {
    int start = 1;  
    int end = MAXNUM;
    int mid = (start + end) / 2;
    int result = 1;

    while(start <= end) {
        reset_arr(stones, arr);
        if(cross(mid, k, arr)) {    //  mid명이 건널 수 있을 경우 더 많은 사람이 건널 수 있나 확인해야 함
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
    int answer = 0;
    vector<int> arr;
    reset_arr(stones, arr);

    // for(auto iter = stones.begin(); iter != stones.end(); iter++)
    //     cout << *iter << ' ';
    // cout << '\n';

    answer = binary_search(k, stones, arr);

    return answer;
}