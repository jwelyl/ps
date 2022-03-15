// https://programmers.co.kr/learn/courses/30/lessons/17682
#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    string shots[3] = {"", "", ""};
    int prev_score[3] = {0, 0, 0};
    int cur_shot = 0;
   
    for(int i = 0; i < dartResult.size(); i++) {
        if('0' <= dartResult[i] && dartResult[i] <= '9')
            shots[cur_shot].push_back(dartResult[i]);
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            shots[cur_shot].push_back(dartResult[i]);
            if(i + 1 == dartResult.size() || (dartResult[i + 1] != '*' && dartResult[i + 1] != '#'))
                cur_shot++;
        }
        else {
            shots[cur_shot].push_back(dartResult[i]);
            cur_shot++;
        }
    }

    for(int i = 0; i < 3; i++) {
        string score;
        string bonus;
        string option;
        int score_int = 0;  //  이번 샷에서 실제 얻는 점수(정수형)

        if(shots[i][1] == '0') {
            score = shots[i].substr(0, 2);
            bonus = shots[i][2];
            option = shots[i][shots[i].size() - 1];
        }
        else {
            score = shots[i].substr(0, 1);
            bonus = shots[i][1];
            option = shots[i][shots[i].size() - 1];
        }
        if(option != "*" && option != "#") option = "";

        if(bonus == "S")
            score_int = (int)pow(stoi(score), 1);
        else if(bonus == "D")
            score_int = (int)pow(stoi(score), 2);
        else if(bonus == "T")
            score_int = (int)pow(stoi(score), 3);

        if(option == "") {
            answer += score_int;
            prev_score[i] = score_int;
        }
        else if(option == "*") {
            score_int *= 2; //  이번에 얻는 점수 두 배
            
            if(i >= 1)    //  지난 번에 얻은 점수도 두배 해야하므로
                answer += prev_score[i - 1];  //  지난 번에 얻은 점수를 추가로 더해줌 
            answer += score_int;
            prev_score[i] = score_int;
        }
        else if(option == "#") {
            score_int *= -1;    //  이번에 얻는 점수 -1배
            answer += score_int;
            prev_score[i] = score_int;
        }
    }

    return answer;
}