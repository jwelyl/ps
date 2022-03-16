#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
int cnt;    //  회전시켜야할 사각형 개수
vector<vector<int> > arr;

void rotate(int cnt) {  //  cnt번째 사각형을 R번 회전시킴
    int n = N - cnt - 1;
    int m = M - cnt - 1;
    int rot = R % (2 * (n - cnt + 1) + 2 * (m - cnt + 1) - 4);  //  실제 회전 수 rot = R mod (한 바퀴 회전 수)

    // cout << cnt << "번째 사각형 실제 회전 횟수 : " << rot << "\n";

    //  r번 회전
    for(int r = 0; r < rot; r++) {
        int tmp = arr[cnt][cnt];    //  왼쪽 위 모서리 임시 저장

        //  위쪽 벽(왼쪽 <- 오른쪽)
        for(int i = cnt; i < m; i++)
            arr[cnt][i] = arr[cnt][i + 1];
        //  오른쪽 벽(위쪽 <- 아래쪽)
        for(int i = cnt; i < n; i++)
            arr[i][m] = arr[i + 1][m];
        //  아래쪽 벽(왼쪽 -> 오른쪽)
        for(int i = m; i > cnt; i--)
            arr[n][i] = arr[n][i - 1];
        //  왼쪽 벽(위쪽 -> 아래쪽)
        for(int i = n; i > cnt; i--)
            arr[i][cnt] = arr[i - 1][cnt];
        //  기존 왼쪽 위 모서리 알맞은 위치에 배치
        arr[cnt + 1][cnt] = tmp;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    arr.assign(N, vector<int>());

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }

    cnt = min(N, M) / 2;

    for(int i = 0; i < cnt; i++) {  //  i(0 ~ cnt - 1)번째 사각형을 회전시킴
        rotate(i);  //  i번째 사각형을 R번 회전시킴
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}