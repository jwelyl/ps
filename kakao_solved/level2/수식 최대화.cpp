// https://programmers.co.kr/learn/courses/30/lessons/67257
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define ADD        0
#define SUB        1
#define MUL        2

using namespace std;

typedef long long LL;

vector<char> operators;
vector<LL> operands;

LL operate(LL opr1, LL opr2, char opt) {
    LL result;

    if(opt == '+')      result = opr1 + opr2;
    else if(opt == '-') result = opr1 - opr2;
    else if(opt == '*') result = opr1 * opr2;

    return result;
}

long long solution(string expr) {
    char opt[] = {'+', '-', '*'};
    vector<int> opt_num;
    long long answer = 0;
    string num = "";

    opt_num.push_back(ADD);
    opt_num.push_back(SUB);
    opt_num.push_back(MUL);

    for(int i = 0; i <= expr.size(); i++) {
        if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
            operators.push_back(expr[i]);
            operands.push_back(stoi(num));
            num = "";
        }
        else num += expr[i];
    }
    operands.push_back(stoi(num));

    // for(int i = 0; i < operators.size(); i++)
    //     cout << operators[i];
    // cout << '\n';

    // for(int i = 0; i < operands.size(); i++)
    //     cout << operands[i] << ' ';
    // cout << '\n';

    do {
        vector<char> tmp_opt = operators;
        vector<LL> tmp_opr = operands;

        for(int i = 0; i < opt_num.size(); i++) {
            char cur_opt = opt[opt_num[i]];

            for(int j = 0; j < tmp_opt.size(); j++) {
                if(tmp_opt[j] == cur_opt) {
                    tmp_opr[j] = operate(tmp_opr[j], tmp_opr[j + 1], tmp_opt[j]);
                    tmp_opr.erase(tmp_opr.begin() + j + 1);
                    tmp_opt.erase(tmp_opt.begin() + j);
                    j--;
                }
            }
        }
        answer = max(answer, abs(tmp_opr[0]));

    } while(next_permutation(opt_num.begin(), opt_num.end()));

    return answer;
}

int main(void) {
    solution("100-200*300-500+20");
}