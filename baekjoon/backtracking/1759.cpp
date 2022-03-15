#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<char, int> vowels;

int L, C;
vector<char> chs;
vector<char> ans;
int n_vowels = 0;   //  모음 개수
int n_consonant = 0; //  자음 개수

void dfs(int idx, int depth) {
    bool is_vowel = false;
    if(vowels.find(chs[idx]) != vowels.end()) {   //  모음일 경우
        // cout << "이게 모음? " <<  chs[idx] << '\n';
        is_vowel = true;
        n_vowels += 1;
    }
    else n_consonant += 1;
    ans.push_back(chs[idx]);

    if(depth == L) {    //  L자리 수 암호 생성됨
        if(n_vowels >= 1 && n_consonant >= 2) { //  만들어진 암호에 모음이 1개 이상일 경우 조건 만족
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i] << ' ';
            cout << '\n';
        }
    }
    else {
        for(int i = idx + 1; i < chs.size(); i++)
            dfs(i, depth + 1);
    }

    if(is_vowel) {    //  모음을 제거할 경우
        // cout << "제거되는 문자 : " << ans.back() << '\n';
        n_vowels -= 1;
    }
    else n_consonant -= 1;
    ans.pop_back();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> L >>C;
    cin.ignore();

    //  모음
    vowels['a'] = 1; vowels['e'] = 1; vowels['i'] = 1; vowels['o'] = 1; vowels['u'] = 1;

    for(int i = 0; i < C; i++) {
        char ch;
        cin >> ch;
        chs.push_back(ch);
    }
    sort(chs.begin(), chs.end());

    for(int i = 0; i < chs.size(); i++)
        dfs(i, 1);

    return 0;
}