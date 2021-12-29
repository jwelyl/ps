// https://programmers.co.kr/learn/courses/30/lessons/17680
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_hit(vector<pair<string, int> >& cache, string city) {
    bool ret = false;   //  hit일 경우 true, miss일 경우 false 반환
    const char* city_str = city.c_str();

    for(int i = 0; i < cache.size(); i++) {
        const char* cache_str = cache[i].first.c_str();
        if(cache[i].first != "") 
            cache[i].second += 1;   //  마지막으로 참조된 이후 term 증가

        if(!ret && !strcasecmp(cache_str, city_str)) {
            ret = true;
            cache[i].second = 0;    //  hit으로 참조되었으므로 0으로 reset
        }
    }

    return ret;
}

int find_miss_pos(vector<pair<string, int> > cache) {
    int oldest = -1;
    int ret = -1;

    for(int i = 0; i < cache.size(); i++) { //  빈 자리 있나 확인
        if(cache[i].first == "") {
            ret = i;        
            break;
        }
    }

    if(ret == -1) { //  빈 자리가 없을 경우
        for(int i = 0; i < cache.size(); i++) {
            if(oldest < cache[i].second) {
                oldest = cache[i].second;
                ret = i;
            }
        }
    }

    return ret;
}

void print_cache(vector<pair<string, int> > cache) {
    cout << "\ncurrent_cache\n";

    for(int i = 0; i < cache.size(); i++) {
        if(cache[i].first == "")
            cout << "empty (";
        else cout << cache[i].first << " (";

        cout << cache[i].second << ")\n";
    }

    cout << "---------------------------------\n";
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<pair<string, int> > cache(cacheSize, make_pair("", 0));

    if(cacheSize == 0)     //  cache 없을 경우 모든 경우가 miss임
        answer = 5 * cities.size();
    else {
        for(int i = 0; i < cities.size(); i++) {
            // print_cache(cache);

            if(is_hit(cache, cities[i]))
                answer += 1;
            else {
                int idx = find_miss_pos(cache);
                answer += 5;

                cache[idx].first = cities[i];
                cache[idx].second = 0;
            }
        }
    }
    return answer;
}