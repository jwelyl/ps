#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<bool> mask;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
        mask.push_back(true);
    }
    for(int i = 0; i < M; i++)
        mask[i] = false;
    sort(nums.begin(), nums.end());

    do {
        for(int i = 0; i < mask.size(); i++) {
            if(!mask[i])
                cout << nums[i] << " ";
        }
        cout << '\n';
    } while(next_permutation(mask.begin(), mask.end()));

    return 0;
}