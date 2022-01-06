// https://programmers.co.kr/learn/courses/30/lessons/60057
#include <string>
#include <vector>
// #include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();

    for(int i = 1; i <= s.length(); i++) {  //  i : unit 길이
        string compressed = "";
        int pos = 0;
        int repeat; //  반복 횟수

        // cout << "자르는 개수 : " << i << '\n';

        while(true) {
            if(pos >= s.size()) break;

            string unit = s.substr(pos, i); //  분할 단위 문자열
            // cout << "pos : " << pos << '\n';
            // cout << "unit = " << unit << '\n';
          
            repeat = 0;

            while(true) {
                if(pos >= s.size()) break;

                // cout << "s.substr(pos + i, i) = " << s.substr(pos + i, i) << '\n';
                // cout << "s.substr(" << pos << ", " << i << ") = " << s.substr(pos, i ) << '\n';
                if(unit == s.substr(pos, i)) {
                    // cout << "일치\n";
                    pos = pos + i;
                    repeat += 1;

                    if(pos >= s.size()) {
                        if(repeat == 1)
                            compressed += unit;
                        else 
                            compressed += to_string(repeat) + unit;
                        // cout << "중간 압축된 문자열 : " << compressed << '\n';
                        break;  
                    }
                }
                else {
                    // cout << "불일치\n";
                    // pos = pos + i;

                    if(repeat == 1)
                        compressed += unit;
                    else 
                        compressed += to_string(repeat) + unit;

                    // cout << "중간 압축된 문자열 : " << compressed << '\n';
                    break;
                }
            }
        }

        // cout << "자르는 개수 : " << i << ", 최종 압축된 문자열 : " << compressed << '\n';

        if(answer > compressed.size())
            answer = compressed.size(); 
    }

    return answer;
}

// int main(void) {
//     string s;
//     int answer;
//     cin >> s;

//     answer = solution(s);
//     cout << "solution : " << answer << '\n';
//     return 0;
// }