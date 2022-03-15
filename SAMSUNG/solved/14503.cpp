#include <iostream>
#include <vector>
#define EMPTY       0
#define WALL        1
#define CLEAN      -1
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<vector<int> > room; //  0은 아직 청소하지 않은 빈칸, 1은 벽, -1은 청소한 빈칸

int N, M, ans = 0;
int cur_y, cur_x, cur_d;     //  청소기 현재 위치 (cur_y, cur_x), 현재 바라보는 방향 cur_d

//  현재 바라보는 방향에서 왼쪽으로 한 번 회전
void turn_left() {
    // cur_d = (cur_d - 1) % 4;
    cur_d = (cur_d + 3) % 4;
}

bool can_move(int ny, int nx) {
    return !(ny < 0 || ny >= N || nx < 0 || nx >= M || room[ny][nx] == WALL);
}

//  현재 바라보는 방향 기준 왼쪽 칸 청소 가능한지 확인
bool check_left() {
    // int left = (cur_d - 1) % 4; 
    int left = (cur_d + 3) % 4;

    if(room[cur_y + dy[left]][cur_x + dx[left]] == EMPTY)
        return true;
    else
        return false;
}

//  현재 바라보는 방향으로 한 칸 이동
bool move_front() {
    int ny = cur_y + dy[cur_d];
    int nx = cur_x + dx[cur_d];

    //  바라보는 방향이 벽이라 움직일 수 없을 경우
    if(!can_move(ny, nx))
        return false;
    
    //  이미 청소한 곳일 경우
    if(room[ny][nx] == CLEAN)
        return false;
    
    //  이동
    cur_y = ny;
    cur_x = nx;
    return true;
}

//  현재 바라보는 방향을 유지한 채 후진
bool move_back() {
    int back_d = (cur_d + 2) % 4;   //  후진 방향
    int ny = cur_y + dy[back_d];
    int nx = cur_x + dx[back_d];

    //  후진 방향의 칸이 벽이라 움직일 수 없을 경우
    if(!can_move(ny, nx))
        return false;

    //  후진
    cur_y = ny;
    cur_x = nx;
    return true;
}

//  현재 위치한 칸 청소
void clean() {
    if(room[cur_y][cur_x] == EMPTY) {
        room[cur_y][cur_x] = CLEAN;
        ans += 1;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cout << (3 % 4) << '\n';

    cin >> N >> M;
    room.assign(N, vector<int>(M, 0));

    cin >> cur_y >> cur_x >> cur_d;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) 
            cin >> room[i][j];
    }
    
    bool cleanup = true;    //  true일땐 while문 시작에서 청소함, 아닐 경우 청소 안함
    while(true) {
        // cout << "In while\n";
        bool flag = false;
        
        if(cleanup) {
            // cout << "(" << cur_y << ", " << cur_x << ") 청소!\n";
            clean();    //  현재 칸 청소함
        }
        
        // cout << "인접한 4칸 탐색 시작\n";
        for(int i = 0; i < 4; i++) {
            if(check_left()) {  //  바라보는 방향 기준 왼쪽 칸 청소 가능할 경우
                turn_left();    //  왼쪽으로 회전
                move_front();   //  이동
                flag = true;
                break;
            }
            else    //  왼쪽 칸 청소 불가할 경우 
                turn_left();    //  왼쪽으로 회전
        }
        // cout << "인접한 4칸 탐색 끝\n";


        if(flag) {  //  인접 4칸 탐색하면서 청소할 칸 찾은 경우
            // cout << "인접 4칸 중 청소할 칸 있을 경우\n";
            cleanup = true;
            continue;
        }
        else {  //  인접 4칸 중에 청소할 칸이 없을 경우
            // cout << "후진 가능한지 확인\n";
            if(!move_back())    //  후진할 수 없을 경우
                break;         //  작동 종료
            
            // cout << "후진!\n";
            cleanup = false;
            continue;
        }
    }

    cout << ans << "\n";
    return 0;
}