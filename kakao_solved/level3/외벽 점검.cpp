// https://programmers.co.kr/learn/courses/30/lessons/60062
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int n_friend = dist.size();     //  친구 수
    int n_weak = weak.size();       //  취약 지점 개수
    int answer = n_friend + 1;

    for(int i = 0; i < n_weak; i++) //  취약 지점을 원형으로 배치
        weak.push_back(weak[i] + n);
    
    // for(int i = 0; i < weak.size(); i++)
    //     cout << weak[i] << ' ';
    // cout << '\n';

    for(int i = 0; i < n_weak; i++) {   //  첫 번째 친구가 탐색을 시작할 위치(첫 번째로 탐색할 취약 지점의 위치)
        do {
            int tmp = 1;    //  탐색에 필요한 친구 수
            int end = weak[i] + dist[tmp - 1];  //  현재 친구들로 가장 멀리까지 탐색한 위치

            for(int j = i + 1; j < i + n_weak; j++) {
                if(end < weak[j]) { //  현재 친구들로는 다음 취약 지점까지 도달할 수 없는 경우
                    tmp++;  //  친구 한 명 증원
                    end = weak[j] + dist[tmp - 1];  //  다음 친구는 weak[j]부터 시작하면 됨
                    
                    if(tmp > n_friend)
                        break;
                }
            }
            
            answer = min(answer, tmp);
        } while(next_permutation(dist.begin(), dist.end()));
    }

    if(answer > n_friend)
        answer = -1;

    return answer;
}