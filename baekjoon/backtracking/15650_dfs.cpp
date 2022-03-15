#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ans;

void print_ans() {
    for(int i = 0; i < M; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

void dfs(int num, int depth) {
    ans.push_back(num);

    if(depth == M) 
        print_ans();
    else {
        for(int i = num + 1; i <= N; i++)
            dfs(i, depth + 1);
    }

    ans.pop_back();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        dfs(i, 1);

    return 0;
}