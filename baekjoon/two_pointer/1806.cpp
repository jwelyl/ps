#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> arr;
vector<int> sum;    //  누적합

int partial_sum(int s, int e) { //  arr의 index s부터 e 까지의 부분합 반환
    if(s == 0)
        return sum[e];
    else
        return sum[e] - sum[s - 1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sum.assign(N, 0);
    sum[0] = arr[0];

    for(int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + arr[i];

    // for(int i = 0; i < N; i++)
    //     cout << arr[i] << ' ';
    // cout << '\n';

    // for(int i = 0; i < N; i++)
    //     cout << sum[i] << ' ';
    // cout << '\n';
    
    int start = 0, end = 0;
    int ans = N;        //  부분합이 S 이상인 부분 수열의 길이
    bool ok = false;    //  부분합이 S 이상인 것이 존재할 경우 true
    while(start < N && end < N) {
        if(partial_sum(start, end) < S)
            end++;  //  부분합이 S 미만이므로 구간을 더 크게 잡아야 함
        else {
            // cout << "[start, end] : [" << start << ", " << end << "]\n";  
            ok = true;
            ans = min(ans, end - start + 1);

            if(start == end) break; //  start와 end가 같을 경우 최소 구간임
            start++;    //  부분합이 S보다 크거나 같으므로 구간을 더 작게 잡아서 최소 구간을 찾음
        }
    }

    if(!ok)
        ans = 0;
    cout << ans << '\n';

    return 0;    
}