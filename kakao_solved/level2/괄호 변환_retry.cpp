// https://programmers.co.kr/learn/courses/30/lessons/60058
#include <string>
#include <vector>

using namespace std;

//  괄호 문자열이 올바른지 검사
bool is_corrected(string w) {
    int ln = 0, rn = 0;
    bool ret = true;

    for(int i = 0; i < w.size(); i++) {
        if(w[i] == '(') ln++;
        else if(w[i] == ')') rn++;

        if(ln < rn) {   //  오른쪽 괄호가 왼쪽 괄호보다 먼저 나올 경우
            ret = false;
            break;
        }
    }

    if(ln != rn) ret = false;    //  괄호 개수가 맞지 않을 경우
    return ret;
}

string func(string w) {
    if(w == "" || is_corrected(w))  //  빈 문자열이거나 올바른 괄호 문자열일 경우 그대로 반환
        return w;

    string u, v;
    int wln = 0, wrn = 0;   //  각각 w의 ( 개수, ) 개수
    int idx;
    for(idx = 0; idx < w.size(); idx++) {
        if(w[idx] == '(') wln++;
        else if(w[idx] == ')') wrn++;

        if(wln == wrn)  //  u가 최소 균형 잡힌 괄호문자열이 될 경우
            break;
    }

    u = w.substr(0, idx + 1);
    v = w.substr(idx + 1);

    if(is_corrected(u))
        return u + func(v);
    else {
        string ret = "(" + func(v) + ")";

        u.pop_back();
        for(int i = 1; i < u.size(); i++) {
            if(u[i] == '(')
                ret += ")";
            else
                ret += "(";
        }

        return ret;
    }
}

string solution(string p) {
    string answer = func(p);
    return answer;
}