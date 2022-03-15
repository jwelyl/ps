#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        nums.push_back(i);
    
    do {
        for(int i = 0; i < M; i++)
            cout << nums[i] << ' ';
        cout << '\n';

        reverse(nums.begin() + M, nums.end());
    } while(next_permutation(nums.begin(), nums.end()));

    return 0;
}