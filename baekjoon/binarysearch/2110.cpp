#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
int ans;
vector<int> houses;

int binary_search() {
    int start = 1;                              //  임의의 두 집 사이의 최소 거리
    int end = houses.back() - houses.front();   //  첫 집과 마지막 집 사이의 거리(최대 거리)
    int mid = (start + end) / 2;
    int ret;

    while(start <= end) {
        int cnt = 1;    //  설치한 공유기 개수(첫 번째 집에 설치한 1개를 제외하면 C-1개가 되어야 함)

        int pos = 0;    //  가장 최근에 공유기 설치한 집 index
        for(int i = 1; i < N; i++) {
            if(houses[i] >= houses[pos] + mid) {    //  새로운 설치 가능한 집 발견
                cnt += 1;
                pos = i;
            }
        }

        if(cnt >= C) {  //  현재 거리로 공유기를 충분히 설치할 수 있을 경우 거리를 증가시켜봄.
            ret = mid;
            start = mid + 1;
        }
        else  //  현재 거리로는 공유기를 전부 설치할 수 없으므로 거리를 감소시켜봄.
            end = mid - 1;
        
        mid = (start + end) / 2;
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        houses.push_back(x);
    }
    sort(houses.begin(), houses.end());

    ans = binary_search();
    cout << ans << '\n';
    return 0;
}