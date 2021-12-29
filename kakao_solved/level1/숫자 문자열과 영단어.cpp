// https://programmers.co.kr/learn/courses/30/lessons/81301
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int start = 0;
    string result = "";
    
    for(int i = 0; i < s.length(); ) {
        if('0' <= s[i] && s[i] <= '9') {
            result += s[i];
            i++;
            continue;
        }
        else {
            if(s[i] == 'z') {
                result += '0';
                i += 4;
                continue;
            }
            else if(s[i] == 'o') {
                result += '1';
                i += 3;
            }
            else if(s[i] == 'e') {
                result += '8';
                i += 5;
            }
            else if(s[i] == 'n') {
                result += '9';
                i += 4;
            }
            else if(s[i] == 't') {
                if(s[i + 1] == 'w') {
                    result += '2';
                    i += 3;
                }
                else if(s[i + 1] == 'h') {
                    result += '3';
                    i += 5;
                }
            }
            else if(s[i] == 'f') {
                if(s[i + 1] == 'o') {
                    result += '4';
                    i += 4;
                }
                else if(s[i + 1] == 'i') {
                    result += '5';
                    i += 4;
                }
            }
            else if(s[i] == 's') {
                if(s[i + 1] == 'i') {
                    result += '6';
                    i += 3;
                }
                else if(s[i + 1] == 'e') {
                    result += '7';
                    i += 5;
                }
            }
        }
    }

    answer = stoi(result);

    return answer;
}