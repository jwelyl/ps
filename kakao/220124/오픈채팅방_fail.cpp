// https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>

#define IN          0
#define OUT         1

using namespace std;

unordered_map<string, string> hashmap;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> answer_id;
    vector<int> answer_cmd;

    for(int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string tmp;
        vector<string> words;   //  words[0] : Enter, Change, Leave, words[1] : user id, words[2] : nickname

        while(ss >> tmp)
            words.push_back(tmp);
        
        if(words[0] == "Enter") {
            if(hashmap.find(words[1]) == hashmap.end()) {   //  새로운 사용자가 들어온 경우
                hashmap[words[1]] = words[2];   //  새로운 사용자건, 기존 인원이 이름 바꾸건 
                answer.push_back(words[2] + "님이 들어왔습니다.");
                answer_id.push_back(words[1]);
                answer_cmd.push_back(IN);
            }
            else {  //  기존 사용자가 나갔다 (닉네임 바꾸고) 다시 들어온 경우 
                hashmap[words[1]] = words[2];

                //  기존 내용 변경
                for(int j = 0; j < answer.size(); j++) {
                    if(answer_id[j] == words[1]) {  //  userid를 확인하여 바꿔야 되는 부분인지 확인
                        if(answer_cmd[j] == IN)
                            answer[j] = hashmap[words[1]] + "님이 들어왔습니다.";
                        else
                            answer[j] = hashmap[words[1]] + "님이 나갔습니다.";
                    }
                }
                //  새로 들어온 내용 추가
                answer.push_back(words[2] + "님이 들어왔습니다.");
                answer_id.push_back(words[1]);
                answer_cmd.push_back(IN);
            }
        }
        else if(words[0] == "Change") {
            hashmap[words[1]] = words[2];

            for(int j = 0; j < answer.size(); j++) {
                if(answer_id[j] == words[1]) {  //  userid를 확인하여 바꿔야 되는 부분인지 확인
                    if(answer_cmd[j] == IN)
                        answer[j] = hashmap[words[1]] + "님이 들어왔습니다.";
                    else
                        answer[j] = hashmap[words[1]] + "님이 나갔습니다.";
                }
            }
        }
        else {
            answer.push_back(words[2] + "님이 나갔습니다.");
            answer_id.push_back(words[1]);
            answer_cmd.push_back(OUT);
        }
    }
    
    return answer;
}