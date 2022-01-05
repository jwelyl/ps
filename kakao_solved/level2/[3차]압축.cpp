//  https://programmers.co.kr/learn/courses/30/lessons/17684
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int num = 1;
unordered_map<string, int> dict;

void init_dict() {
    char c = 'A';
    for(int i = 0; i < 26; i++) {
        string tmp = "";
        dict[tmp.insert(0, 1, c)] = num++;
        c += 1;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    
    init_dict();

    while(msg.size() > 0) {
        string w = "", c = "";

        for(int i = 0; i < msg.size(); i++) {
            if(dict[w + msg[i]] != 0) 
                w = w + msg[i];
            else break;
        }

        answer.push_back(dict[w]);
        if(w.size() < msg.size())
            c = msg[w.size()];

        msg = msg.substr(w.size(), msg.size() - w.size());
        dict[w + c] = num++;
    }

    return answer;
}