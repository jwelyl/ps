#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 987654321
using namespace std;

int N, M, K;
int ans = MAX;
vector<vector<int> > origin;    //  처음 주어진 원본 배열
vector<vector<int> > A;      //  연산할 배열
vector<vector<int> > square; //  부분 정사각배열
vector<pair<pair<int, int>, int> > opts;
vector<int> indices;

void print_array() {
    cout << "============================================\n";
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
    cout << "============================================\n\n";
}

void print_partial_square() {
    cout << "++++++++++++++++++++++++++++++++++++++++++++++\n";
    for(int i = 0; i < square.size(); i++) {
        for(int j = 0; j < square[i].size(); j++)
            cout << square[i][j] << " ";
        cout << "\n";
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}

//  문제 조건에 맞는 배열 최소값을 찾아 반환함
int arr_min_val() {
    // cout << "최솟값 계산 함수\n";
    int ret = MAX;

    for (int i = 1; i <= N; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= M; j++)
            tmp += A[i][j];

        ret = min(ret, tmp);
    }

    return ret;
}

//  부분 정사각형을 추출함
void make_partial_square(int r, int c, int s) {
    // cout << "r = " << r << ", c = " << c << ", s = " << s << "\n"; 
    // cout << "부분 정사각형 추출 함수 시작\n";

    // cout << "1!!\n";
    square.assign(2 * s + 1, vector<int>(2 * s + 1, 0));
    // cout << "square 세로 길이 = " << square.size() << "\n";
    // cout << "square 가로 길이 = " << square[0].size() << "\n";

    // cout << "2!!\n";
    for(int i = r - s; i <= r + s; i++) {
        for(int j = c - s; j <= c + s; j++) {
            // cout << "(" << i - r + s << ", " << j - c + s <<")\n";
            square[i - r + s][j - c + s] = A[i][j];
        }
        // cout << "end\n";
    }

    // cout << "회전하기 전 부분 정사각형\n";
    // print_partial_square();
}

//  부분 정사각형을 시계방향으로 한 칸씩 돌림
void rotate_square() {
    int cnt = square.size() / 2;

    // cout << "1!!!!!!!!!!!\n";
    for(int t = 0; t < cnt; t++) {
        // cout << "2!!!!!!!!!!!!!!!\n";
        int n = square.size() - t - 1;
        // cout << "2!!!!!!!!!!!!!!!\n";

        int tmp = square[t][n];

        // cout << "up!!!!!!!!!!!!!!!\n";
        //  위쪽 변(왼쪽 -> 오른쪽)
        for(int i = n; i > t; i--)
            square[t][i] = square[t][i - 1];

        // cout << "left!!!!!!!!!!!!!!!\n";
        //  왼쪽 변(아래쪽 -> 위쪽)
        for(int i = t; i < n; i++)
            square[i][t] = square[i + 1][t];

        // cout << "right!!!!!!!!!!!!!!\n";
        //  아래쪽 변(오른쪽 -> 왼쪽)
        for(int i = t; i < n; i++)
            square[n][i] = square[n][i + 1];
        //  오른쪽 변(위쪽 -> 아래쪽)

        // cout << "down!!!!!!!!!!!!!!\n";
        for(int i = n; i > t; i--)
            square[i][n] = square[i - 1][n];
        //  원래 (t, n) 값 (t + 1, n)에 배치

        // cout << "백업 제외 회전 완료!!!!!!!!!!!\n";
        square[t + 1][n] = tmp;
    }
    // cout << "OK!!!!!!!!!!!\n";


    // cout << "회전한 다음 부분 정사각형\n";
    // print_partial_square();
}

//  회전시킨 부분 정사각형을 배열에 옮긴 후 부분 정사각형 해제함
void paste_partial_square(int r, int c, int s) {
    // cout << "부분 정사각형 붙이는 함수 시작\n";

    for(int i = r - s; i <= r + s; i++) {
        for(int j = c - s; j <= c + s; j++)
            A[i][j] = square[i - r + s][j - c + s];
    }

    vector<vector<int> >().swap(square);

    // cout << "부분 정사각형 붙이는 함수 종료\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    origin.assign(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> origin[i][j];

    for (int i = 0; i < K; i++) {
        int r, c, s;

        cin >> r >> c >> s;
        opts.push_back(make_pair(make_pair(r, c), s));
        indices.push_back(i);
    }

    do {
        //  원본 배열을 A에 복사
        A.assign(origin.size(), vector<int>(origin[0].size(), 0));
        copy(origin.begin(), origin.end(), A.begin());       

        for(int i = 0; i < indices.size(); i++) {
            int idx = indices[i];
            int r = opts[idx].first.first;
            int c = opts[idx].first.second;
            int s = opts[idx].second;
            // cout << "(" << r << ", " << c << ", " << s << ")\n";

            make_partial_square(r, c, s);
            
            rotate_square();

            // cout << "회전하기 전 배열\n";
            // print_array();
            paste_partial_square(r, c, s);
            // cout << "회전한 다음 배열\n";
            // print_array();
        }

        int res = arr_min_val();
        // cout << "이번 순서 결과 : " << res << "\n\n";
        ans = min(ans, res);
        vector<vector<int> >().swap(A);
    } while (next_permutation(indices.begin(), indices.end()));

    cout << ans << "\n";
    return 0;
}