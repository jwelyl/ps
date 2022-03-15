#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<bool> tmp;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    tmp.assign(N, true);
    for(int i = 1; i <= N; i++)
        nums.push_back(i);
    for(int i = 0; i < M; i++)
        tmp[i] = false;

    do {
        for(int i = 0; i < N; i++) {
            if(!tmp[i])
                cout << nums[i] << ' ';
        }
        cout << '\n';
    } while(next_permutation(tmp.begin(), tmp.end()));

    return 0;
}