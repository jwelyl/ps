// https://programmers.co.kr/learn/courses/30/lessons/17680
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#include <iostream>
#define H       1   //  Cache Hit
#define M       5   //  Cache Miss
#define NONE   -1   //  Cache의 slot이 빔

using namespace std;

int time_stamp = 0;
vector<pair<int, string> > cache;

bool is_in_cache(string target) {
    for(int i = 0; i < cache.size(); i++) {
        if(!strcasecmp(cache[i].second.c_str(), target.c_str())) {
            cache[i].first = time_stamp;
            sort(cache.begin(), cache.end());
            return true;
        }
    }

    return false;
}

void replace(string target) {
    cache[0].first = time_stamp;
    cache[0].second = target;
    sort(cache.begin(), cache.end());
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    cache.assign(cacheSize, make_pair(NONE, ""));

    for(int i = 0; i < cities.size(); i++) {
        string target = cities[i];

        if(cacheSize == 0)     //  cache를 사용하지 않는 경우
            time_stamp += M;
        else if(is_in_cache(target))  //  cache 사용하고 HIT일 경우
            time_stamp += 1;
        else {  //  cache 사용하는데 MISS일 경우
            replace(target);
            time_stamp += 5;
        }
    }

    answer = time_stamp;
    return answer;
}