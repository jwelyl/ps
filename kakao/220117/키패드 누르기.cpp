// https://programmers.co.kr/learn/courses/30/lessons/67256
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
// #include <iostream>

using namespace std;

char numbers[4][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#'};
int ly = 3, lx = 0, ry = 3, rx = 2; 

unordered_map<int, int> num_y;  //  각 숫자의 키패드의 y 위치
unordered_map<int, int> num_x;  //  각 숫자의 키패드의 x 위치

void init_num_pos() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            if('0' <= numbers[i][j] && numbers[i][j] <= '9') {
                num_y[numbers[i][j] - '0'] = i;
                num_x[numbers[i][j] - '0'] = j;
            }
        }
    }
}

int manhattan_dist(int y1, int x1, int num) {
    int y2 = num_y[num];
    int x2 = num_x[num];

    return abs(y2 - y1) + abs(x2 - x1);
}

void push_left(string& answer, int num) {
    answer.push_back('L');
    ly = num_y[num];
    lx = num_x[num];
}

void push_right(string& answer, int num) {
    answer.push_back('R');
    ry = num_y[num];
    rx = num_x[num];
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    init_num_pos();
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] % 3 == 1) 
            push_left(answer, numbers[i]);
        else if(numbers[i] % 3 == 0 && numbers[i] != 0) 
            push_right(answer, numbers[i]);
        else {
            int ld = manhattan_dist(ly, lx, numbers[i]);
            int rd = manhattan_dist(ry, rx, numbers[i]);

            // cout << "ld : " << ld << ", rd : " << rd << '\n';

            if(ld < rd) 
                push_left(answer, numbers[i]);
            else if(ld > rd)
                push_right(answer, numbers[i]);
            else {
                if(hand == "left")
                    push_left(answer, numbers[i]);
                else
                    push_right(answer, numbers[i]);
            }
        }
    }

    return answer;
}