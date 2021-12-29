// https://programmers.co.kr/learn/courses/30/lessons/67256
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int y_pos[] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};   //  y_pos[i] : 숫자 i(0~9)의 y 위치
int x_pos[] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};   //  x_pos[i] : 숫자 i(0~9)의 x 위치

int left_y = 3, left_x = 0;     // 왼쪽 엄지 위치
int right_y = 3, right_x = 2;   // 오른쪽 엄지 위치

void push_button(string str, string& answer, int number) {
    if(str == "L") {
        answer += "L";
        left_y = y_pos[number];
        left_x = x_pos[number];
    }
    else if(str == "R") {
        answer += "R";
        right_y = y_pos[number];
        right_x = x_pos[number];
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] % 3 == 1) //  1, 4, 7일 경우
            push_button("L", answer, numbers[i]);
        else if(numbers[i] % 3 == 0 && numbers[i] != 0)    //  3, 6, 9일 경우
            push_button("R", answer, numbers[i]);        
        else {  //  2, 5, 8, 0일 경우
            int left_dist = abs(left_y - y_pos[numbers[i]]) + abs(left_x - x_pos[numbers[i]]);
            int right_dist = abs(right_y - y_pos[numbers[i]]) + abs(right_x - x_pos[numbers[i]]);

            if(left_dist == right_dist) {   //  두 거리가 같을 경우
                if(hand == "left")    //  왼손잡이일 경우
                    push_button("L", answer, numbers[i]);      
                else   //  오른손 잡이일 경우
                    push_button("R", answer, numbers[i]);  
            }
            else if(left_dist < right_dist)  //  왼손이 더 가까울 경우
                push_button("L", answer, numbers[i]);    
            else    //  오른손이 더 가까울 경우
                push_button("R", answer, numbers[i]);  
        }
    }

    return answer;
}