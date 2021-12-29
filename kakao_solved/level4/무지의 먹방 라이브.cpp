// https://programmers.co.kr/learn/courses/30/lessons/42891?language=cpp

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

long long sum(vector<int> food_times) {
    long long ret = 0;

    for(int i = 0; i < food_times.size(); i++)
        ret += food_times[i];

    return ret;
}

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    priority_queue<pair<int, int> > pq;
    long long sum_value = 0;
    long long prev = 0;
    long long len = food_times.size();
    vector<pair<int, int> > result;

    //  전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
    if(sum(food_times) <= k)
        return -1;

    //  시간이 작은 음식부터 뺴야 하므로 우선순위 큐를 이용
    for(int i = 0; i < food_times.size(); i++) {
        // (음식 시간, 음식 번호) 형태로 우선순위 큐에 삽입
        pq.push(make_pair(-food_times[i], i + 1));
    }

    //  sum_value + (현재의 음식 시간 - 이전의 음식 시간) * 현재의 음식 개수와 k 비교
    while(sum_value + ((-pq.top().first) - prev) * len <= k) {
        int now = -pq.top().first;
        pq.pop();
        sum_value += (now - prev) * len;
        //  다 먹은 음식 제외
        len -= 1;
        //  이전 음식 시간 재설정
        prev = now;
    }



    // 남은 음식 중에서 몇 번째 음식인지 확인하여 출력
    while(!pq.empty()) {
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back(make_pair(food_time, num));
    }
    
    //  음식 번호 기준으로 정렬
    sort(result.begin(), result.end(), comp);
    return result[(k - sum_value) % len].second;
}