// https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>

using namespace std;

int log = 0;
unordered_map<string, string> user; //  id, nickname
unordered_map<string, vector<int> > log_num;
vector<pair<string, pair<string, string> > > tmp;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for(int i = 0; i < record.size(); i++) {
        string word[3] = {"", "", ""};  //  각각 명령어, id, nickname
        int pos = 0;

        for(int j = 0; j < record[i].size(); j++) {
            if(record[i][j] == ' ') {
                pos += 1;
                continue;
            }
            word[pos] += record[i][j];            
        }

        if(word[0] == "Enter") {
            if(user.find(word[1]) == user.end()) {  //  새로운 id인 경우
                user[word[1]] = word[2];
                tmp.push_back(make_pair(word[0], make_pair(word[1], string(user[word[1]] + "님이 들어왔습니다."))));
                log_num[word[1]].push_back(log++);
            }
            else {
                user[word[1]] = word[2];

                for(int j = 0; j < log_num[word[1]].size(); j++) {
                    int idx = log_num[word[1]][j];

                    if(tmp[idx].first == "Enter") {
                        tmp[idx].second.second = user[word[1]] + "님이 들어왔습니다.";
                    }
                    else if(tmp[idx].first == "Leave") {
                        tmp[idx].second.second = user[word[1]] + "님이 나갔습니다.";
                    }
                }
                tmp.push_back(make_pair(word[0], make_pair(word[1], string(user[word[1]] + "님이 들어왔습니다."))));
                log_num[word[1]].push_back(log++);
            }
        }
        else if(word[0] == "Leave") {
            tmp.push_back(make_pair(word[0], make_pair(word[1], string(user[word[1]] + "님이 나갔습니다."))));
            log_num[word[1]].push_back(log++);
        }
        else if(word[0] == "Change") {
            user[word[1]] = word[2];

            for(int j = 0; j < log_num[word[1]].size(); j++) {
                int idx = log_num[word[1]][j];

                if(tmp[idx].first == "Enter") {
                    tmp[idx].second.second = user[word[1]] + "님이 들어왔습니다.";
                }
                else if(tmp[idx].first == "Leave") {
                    tmp[idx].second.second = user[word[1]] + "님이 나갔습니다.";
                }
            }
        }
    }

    for(int i = 0; i < tmp.size(); i++)
        answer.push_back(tmp[i].second.second);

    return answer;
}