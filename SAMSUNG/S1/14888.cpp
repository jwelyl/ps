#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

#define MAX         1234567890
#define ADD         0
#define SUB         1
#define MUL         2
#define DIV         3

using namespace std;

int N;
int add, sub, mult, divd;
int min_ans = MAX;          //  최솟값
int max_ans = -MAX;         //  최댓값
vector<int> nums;           //  처음에 주어진 수들
vector<int> oprs;           //  연산자들

template <typename T>
stack<T> make_stack(vector<T> v) {
    stack<T> st;

    for(int i = v.size() - 1; i >= 0; i--)
        st.push(v[i]);

    return st;
}

int calc_value() {
    stack<int> opd_st = make_stack<int>(nums);  //  operand stack
    stack<int> opr_st = make_stack<int>(oprs);  //  operator stack

    while(opd_st.size() > 1) {
        int opd1, opd2, opr;
        int res;
        opd1 = opd_st.top();
        opd_st.pop();
        opd2 = opd_st.top();
        opd_st.pop();
        opr = opr_st.top();
        opr_st.pop();

        if(opr == ADD)
            res = opd1 + opd2;
        else if(opr == SUB)
            res = opd1 - opd2;
        else if(opr == MUL)
            res = opd1 * opd2;
        else
            res = opd1 / opd2;

        opd_st.push(res);
    }

    return opd_st.top();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    // cout << "N : " << N << "\n";
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cin >> add >> sub >> mult >> divd;
    for(int i = 0; i < add; i++)
        oprs.push_back(ADD);
    for(int i = 0; i < sub; i++) 
        oprs.push_back(SUB); 
    for(int i = 0; i < mult; i++) 
        oprs.push_back(MUL);
    for(int i = 0; i < divd; i++) 
        oprs.push_back(DIV);

    do {
        int res = calc_value();
        if(res < min_ans)
            min_ans = res;
        if(res > max_ans)
            max_ans = res;
    } while(next_permutation(oprs.begin(), oprs.end()));
    
    cout << max_ans << "\n" << min_ans << "\n";
    return 0;
}