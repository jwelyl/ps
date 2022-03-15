#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ans;

void dfs(int num, int depth) {
    ans.push_back(num);

    if(depth == M) {
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    else {
        for(int i = num; i <= N; i++)
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