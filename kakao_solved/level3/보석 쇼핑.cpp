// https://programmers.co.kr/learn/courses/30/lessons/67258
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> gmap;
int gnum;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<int> tmp(2, 0);
    int start = 0, end = 0;

    answer.push_back(1);
    answer.push_back(100001);

    for(int i = 0; i < gems.size(); i++)
        gmap[gems[i]] += 1;
    gnum = gmap.size();
    unordered_map<string, int>().swap(gmap);

    while(true) {
        if(gmap.size() == gnum) {   //  모든 종류의 보석을 포함할 경우
            tmp[0] = start + 1;
            tmp[1] = end;

            if(answer[1] - answer[0] > tmp[1] - tmp[0]) //  새로 구한 구간의 길이가 더 짧을 경우
                tmp.swap(answer);   //  answer와 교환

            //  더 짧은 구간 존재하는지 확인
            if(gmap[gems[start]] == 1) {    //  해당 보석을 제거하면 해당 보석이 더 이상 없을 경우
                gmap[gems[start]] = 0;
                gmap.erase(gems[start]);    //  hashmap에서 보석 제거
            }
            else 
                gmap[gems[start]] -= 1;     //  해당 보석 개수 1 감소
            start++;
        }

        else if(end == gems.size())  //  끝에 도달한 경우
            break; 

        
        
        else if(gmap.size() < gnum) {   //  아직 모든 종류의 보석을 포함하지 못한 경우
            gmap[gems[end]] += 1;       //  해당 보석 개수 1 증가
            end++;  
        }
    }
    
    return answer;
}