// https://programmers.co.kr/learn/courses/30/lessons/81303
#include <string>
#include <iterator>
#include <vector>
#include <set>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');

    set<int> table;
    stack<int> hist;    

    for(int i = 0; i < n; i++) table.insert(i);

    auto cur = table.find(k);

    for(string s : cmd) {
        if (s[0] == 'U' || s[0] == 'D') {
            int x = stoi(s.substr(2));
            if(s[0] == 'U') while(x--) cur = prev(cur);
            else while(x--) cur = next(cur);
        }
        else if(s[0] == 'C') {
            hist.push(*cur);
            cur = table.erase(cur);
            if(cur == table.end()) cur = prev(cur);
        }
        else if(s[0] == 'Z') {
            table.insert(hist.top());
            hist.pop();
        }
        else return "";
    }

    for(int i : table) answer[i] = 'O';

    return answer;
}