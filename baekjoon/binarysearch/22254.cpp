#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, X;
int ans;
vector<int> works;  //  작업의 양

void binary_search() {
    int start = 1;  //  이론 상 최소 공정 라인 수
    int end = N;    //  최대 공정 라인 수
    int mid = (start + end) / 2;

    while(start <= end) {
        priority_queue<int> pq;  //  최대 힙
        bool success = true;      //  mid개의 공정 라인에 N개의 작업 배치 성공 시 true, 실패 시 false

        for(int i = 0; i < mid; i++)    //  mid개의 공정 라인
            pq.push(X);

        for(int i = 0; i < works.size(); i++) {
            int max_line = pq.top();    //  가장 시간 많이 남은 공정 라인
            pq.pop();

            if(max_line >= works[i])   //  현재 공정 라인에 작업을 배치할 수 있을 경우
                pq.push(max_line - works[i]);
            else {  //  배치 불가능할 경우, 더 많은 공정 라인이 필요함
                success = false;
                break;
            }
        }

        if(success) {   //  현재 공정 라인으로 충분할 경우 일단 개수 저장 후 공정 라인 개수를 감소시켜봄
            ans = mid;
            end = mid - 1;
        }
        else start = mid + 1;  //  현재 공정 라인으론 부족하므로 공정 라인 개수를 증가시켜야 함
        mid = (start + end) / 2;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> X;
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;
        works.push_back(t);
    }

    binary_search();
    cout << ans << '\n';
    return 0;
}