// https://programmers.co.kr/learn/courses/30/lessons/60057?language=cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int chunk = 1;


int solution(string s) {
    int answer = s.length();
    int n = s.length() / 2;

    for(int i = 1; i <= n; i++) {
        int start = 0;
        string tmp = "";

        while(true) {
            string token;
            int match = 1;

            if(start + i - 1 >= s.length()) {
                tmp += s.substr(start);
                break;
            }
            token = s.substr(start, i);

            for(int j = 1; ; j++) {
                if(start + j * i + i - 1 >= s.length()) {
                    start = start + j * i;
                    break;
                }
                else if(token != s.substr(start + j * i, i)) {
                    start = start + j * i;
                    break;
                }
                else match++;
            }

            if(match >= 2)
                tmp += to_string(match);
            tmp += token;
        }

        if(answer > (int)tmp.length())
            chunk = i;
        answer = min(answer, (int)tmp.length());
    }

    return answer;
}