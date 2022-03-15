#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

int N, M;
// vector<int> nums;
vector<bool> checked;
vector<int> ans;

void print_ans() {
    for(int i = 0; i < M; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

void dfs(int num, int depth) {
    checked[num] = true;
    ans.push_back(num);

    if(depth == M)
        print_ans();
    else {
        for(int i = 1; i <= N; i++) {
            if(!checked[i])
                dfs(i, depth + 1);
        }
    }

    checked[ans.back()] = false;
    ans.pop_back();
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    checked.assign(N + 1, false);
    // for(int i = 0; i <= N; i++)
    //     nums.push_back(i);

    // do {
    //     for(int i = 0; i < N; i++)
    //         cout << nums[i] << ' ';
    //     cout << '\n';
    // } while(next_permutation(nums.begin(), nums.end()));

    for(int i = 1; i <= N; i++)
        dfs(i, 1);

    return 0;
}