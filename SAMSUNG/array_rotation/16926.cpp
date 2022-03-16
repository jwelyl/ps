#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int> > arr;

void rotate_array() {
    int rot = min(N, M) / 2;    //  돌려야 할 사각형 개수

    for(int i = 0; i < rot; i++) {
        int n = N - i - 1;
        int m = M - i - 1;

        int tmp = arr[i][i];    //  tmp에 돌릴 사각형 왼쪽 위 값 임시 저장
        
        //  위쪽 변 : 왼쪽 <- 오른쪽
        for(int j = i; j < m; j++) 
            arr[i][j] = arr[i][j + 1];
        
        //  오른쪽 변 : 위쪽 <- 아래쪽
        for(int j = i; j < n; j++)
            arr[j][m] = arr[j + 1][m];

        //  아래쪽 변 : 왼쪽 -> 오른쪽
        for(int j = m; j > i; j--)
            arr[n][j] = arr[n][j - 1];
        
        //  왼쪽 벽 : 위쪽 -> 아래쪽
        for(int j = n; j > i; j--)
            arr[j][i] = arr[j - 1][i];
        
        arr[i + 1][i] = tmp;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    arr.assign(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    for(int i = 0; i < R; i++)
        rotate_array();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) 
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}