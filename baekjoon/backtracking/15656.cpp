#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> nums;
vector<int> ans;

void dfs(int idx, int depth) {
    ans.push_back(nums[idx]);

    if(depth == M) {
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    else {
        for(int i = 0; i < nums.size(); i++)
            dfs(i, depth + 1);
    }

    ans.pop_back();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++)
        dfs(i, 1);

    return 0;
}