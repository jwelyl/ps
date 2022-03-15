#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M;
int ans = INF;
vector<int> arr;
vector<int> sum;

int partial_sum(int start, int end) {
    if(start == 0)
        return sum[end];
    else
        return sum[end] - sum[start - 1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    arr.assign(N, 0);
    sum.assign(N, 0);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sum[0] = arr[0];
    for(int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + arr[i];

    int start = 0, end = 0;

    while(end < N) {
        int part_sum = partial_sum(start, end);

        if(part_sum < M)
            end++;
        else {
            ans = min(ans, end - start + 1);
            start++;

            if(start > end)
                break;
        }
    }

    if(ans == INF)
        cout << 0 << '\n';
    else
        cout << ans << '\n';

    return 0;
}