// https://programmers.co.kr/learn/courses/30/lessons/60058
#include <string>
#include <vector>

using namespace std;

bool correct_str(string str) {
    int left = 0;

    if(str == "") return true;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(')
            left++;
        else if(str[i] == ')') {
            left--;
            if(left < 0)
                return false;
        }
    }

    return true;
}

string solution(string p) {
    if(p == "") //  빈 문자열인 경우
        return p;

    else {
        string u = "", v = "";
        int uleft = 0, uright = 0, ustart = 0, uend = 0, vstart = 0, vend = p.length() - 1;

        for(int i = 0; i < p.length(); i++) {
            if(p[i] == '(') uleft += 1;
            else if(p[i] == ')') uright += 1;

            if(uleft == uright) {
                uend = i;
                vstart = uend + 1;
                break;
            }
        }

        u = p.substr(0, vstart);
        v = p.substr(vstart, p.npos);

        if(correct_str(u))
            return u + solution(v);
        else {
            string tmp = "(";
            tmp += solution(v);
            tmp += ")";

            for(int i = 1; i < u.length() - 1; i++) {
                if(u[i] == '(')
                    tmp += ")";
                else if(u[i] == ')')
                    tmp += "(";
            }

            return tmp;
        }
    }
}