// https://programmers.co.kr/learn/courses/30/lessons/42889?language=cpp
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<double, int> a, pair<double, int> b) {
    if(a.first == b.first) 
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int> > tmp;
    int len = stages.size();
    double fail;

    //  스테이지 번호를 1부터 N까지 증가
    for(int i = 1; i <= N; i++) {
        int count = 0;
        
        //  해당 스테이지에 있는 사람 수 계산
        for(int j = 0; j < stages.size(); j++) {
            if(stages[j] == i)
                count += 1;
        }

        //  실패율 계산
        if(len == 0)
            fail = 0;
        else
            fail = (double)count / len;

        //  (실패율, 스테이지 번호) 삽입
        tmp.push_back(make_pair(fail, i));
        len -= count;
    }

    //  실패율 기준으로 내림차순 정렬
    sort(tmp.begin(), tmp.end(), comp);

    //  실패율 기준으로 내림차순 정렬된 스테이지 번호 순서대로 저장 
    for(int i = 0; i < tmp.size(); i++) 
        answer.push_back(tmp[i].second);

    return answer;
}