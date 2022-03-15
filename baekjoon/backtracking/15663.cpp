#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> nums;
vector<int> ans;
vector<bool> visited;

void dfs(int idx, int depth) {
    ans.push_back(nums[idx]);
    visited[idx] = true;

    if(depth == M) {
        
    }

    visited[idx] = false;
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
        visited.push_back(false);
    }
    sort(nums.begin(), nums.end());

    return 0;
}