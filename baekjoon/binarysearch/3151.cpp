#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long ans = 0;
vector<int> arr;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    if(arr.size() < 3)
        ans = 0;
    else if(arr.size() == 3) {
        if(arr[0] + arr[1] + arr[2] == 0)
            ans = 1;
        else ans = 0;
    }
    else {
        sort(arr.begin(), arr.end());

        for(int i1 = 0; i1 < arr.size() - 2; i1++) {
            for(int i2 = i1 + 1; i2 < arr.size() - 1; i2++) {
                int target = -(arr[i1] + arr[i2]);
                vector<int>::iterator start = arr.begin() + i2 + 1;
                vector<int>::iterator end = arr.end();

                int i3_start = lower_bound(start, end, target) - arr.begin();   //  target 이상인 수중 가장 작은 수 인덱스
                int i3_end = upper_bound(start, end, target) - arr.begin();     //  target보다 큰 수중 가장 작은 수 인덱스
            
                if(arr[i3_start] == target)
                    ans += (i3_end - i3_start);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}