#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

vector<pair<int, int> > cloud;      //  구름 구성하는 칸들의 위치

int N, M;
int ans = 0;
vector<vector<int> > A;
vector<vector<bool> > disappeared;


// void print_cloud() {
//     cout << "새로 생성된 구름 위치 : ";
//     for(int i = 0; i < cloud.size(); i++)
//         cout << "(" << cloud[i].first << ", " << cloud[i].second << ") ";
//     cout << '\n';
// }

// void print(int num) {
//     cout << "===================================================\n";
//     cout << num << "번째 이동\n";
//     for(int i = 1; i <= N; i++) {
//         for(int j = 1; j <= N; j++)
//             cout << A[i][j] << " ";
//         cout << '\n';
//     }
//     cout << "===================================================\n";
//     print_cloud();
//     cout << "===================================================\n";

// }

void reset() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            disappeared[i][j] = false;
    }
}

//  현재 위치 (y, x)에서 dir 방향으로 n번 간 위치 (ny, nx)
void dir_n_pos(int dir, int n, int y, int x, int& ny, int& nx) {
    int ty, tx;
    
    for(int i = 0; i < n; i++) {
        ty = y + dy[dir];
        tx = x + dx[dir];

        if(ty == 0)
            ty = N;
        else if(ty == N + 1)
            ty = 1;

        if(tx == 0)
            tx = N;
        else if(tx == N + 1)
            tx = 1;

        y = ty;
        x = tx;
    }

    ny = ty;
    nx = tx;
}

//  구름이 dir 방향으로 n번 이동
void move_cloud(int dir, int n) {
    // cout << "이동 전 구름 위치\n";
    // print_cloud();

    for(int i = 0; i < cloud.size(); i++) {
        int ncy, ncx;   //  새 구름 위치
        dir_n_pos(dir, n, cloud[i].first, cloud[i].second, ncy, ncx);
        cloud[i].first = ncy;
        cloud[i].second = ncx;
    }

    // cout << "이동 후 구름 위치\n";
    // print_cloud();
}

//  물 복사
void copy_water(int y, int x) {
    int add = 0;

    for(int i = 2; i <= 8; i += 2) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <= 0 || ny > N || nx <= 0 || nx > N)
            continue;

        if(A[ny][nx] > 0)
            add += 1;
    }

    A[y][x] += add;
}

//  구름이 존재하는 칸에 물 증가 후 구름 사라지기
void rain_cloud() {
    // cout << "In rain_cloud func\n";
    // cout << "for1\n";
    for(int i = 0; i < cloud.size(); i++) {
        int cy = cloud[i].first;
        int cx = cloud[i].second;

        disappeared[cy][cx] = true;
        A[cy][cx] += 1;
    }

    // cout << "for2\n";
    for(int i = 0; i < cloud.size(); i++) {
        int cy = cloud[i].first;
        int cx = cloud[i].second;

        copy_water(cy, cx);
    }

    //  구름 제거
    while(!cloud.empty())
        cloud.pop_back();
}

//  물의 양이 2 이상인 칸에서 구름 생성 후 물 2씩 제거
void form_cloud() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(!disappeared[i][j] && A[i][j] >= 2) {
                cloud.push_back(make_pair(i, j));
                A[i][j] -= 2;
            }
        }
    }
}

void calc_ans() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            ans += A[i][j];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin >> N >> M;

    //  초기 구름 설정
    cloud.push_back(make_pair(N, 1));
    cloud.push_back(make_pair(N, 2));
    cloud.push_back(make_pair(N - 1, 1));
    cloud.push_back(make_pair(N - 1, 2));
    
    A.assign(N + 1, vector<int>(N + 1, 0));
    disappeared.assign(N + 1, vector<bool>(N + 1, false));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) 
            cin >> A[i][j];
    }

    for(int i = 0; i < M; i++) {
        int dir, num;
        cin >> dir >> num;
        
        // cout << "move_cloud" << '\n';
        move_cloud(dir, num);
        // cout << "rain_cloud" << '\n';
        rain_cloud();
        // cout << "form_cloud" << '\n';
        form_cloud();
        // cout << "reset" << '\n';
        reset();
        // print(i);
    }

    calc_ans();
    cout << ans << "\n";

    return 0;
}