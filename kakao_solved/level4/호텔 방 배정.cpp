// https://programmers.co.kr/learn/courses/30/lessons/64063
#include <string>
#include <vector>
#include <unordered_map>
#define INF     1e13
using namespace std;

typedef long long LL;

unordered_map<LL, LL> parents;

LL find_parent(LL number) { //  number 방이 비었을 경우 해당 방 return, 비어 있지 않을 경우 더 크면서 비어 있는 가장 가까운 방 리턴
    if(parents.find(number) == parents.end())   //  해당 방이 비었을 경우 번호 리턴
        return number;
    else // 해당 방보다 번호가 큰 방 중 가장 가까우며 비어있는 방 리턴
        return parents[number] = find_parent(parents[number]);
}

vector<LL> solution(LL k, vector<LL> room_number) {
    vector<LL> answer;

    for(int i = 0; i < room_number.size(); i++) {
        LL number = room_number[i];

        if(parents.find(number) == parents.end()) { //  해당 방이 비었을 경우
            answer.push_back(number);
            parents[number] = find_parent(number + 1);  //  해당 방 번호보다 크며 비어있는 가장 가까운 방 설정
        }
        else {  //  해당 방이 비지 않았을 경우
            LL pos = find_parent(number); 
            answer.push_back(pos);
            parents[pos] = find_parent(pos + 1);
        }
    }
    return answer;
}