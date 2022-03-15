#include <iostream>
#include <vector>
#include <utility>
using namespace std;

//  8방향
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int N, M, K, ans = 0;

vector<vector<vector<pair<pair<int, int>, int> > > > fireballs; //  파이어볼 (질량, 속도, 방향) 저장
vector<vector<vector<pair<pair<int, int>, int> > > > tmp;       //  임시 배열

//  tmp 배열의 vector 비우기
void reset() {
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            vector<pair<pair<int, int>, int> >().swap(tmp[i][j]);

    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= N; j++) {
    //         if(tmp[i][j].size() != 0) {
    //             cout << "reset 실패!!n";
    //             break;
    //         }
    //     }
    // }
}

//  (y, x)에 있는 파이어볼 하나가 한번에 speed번 만큼 dir 방향으로 이동하여 (ny, nx)에 도달
void move(int y, int x, int speed, int dir, int& ny, int& nx) {
    for(int i = 0; i < speed; i++) {
        ny = y + dy[dir];
        nx = x + dx[dir];

        if(ny == 0)
            ny = N;
        else if(ny == N + 1)
            ny = 1;
        if(nx == 0)
            nx = N;
        else if(nx == N + 1)
            nx = 1;

        y = ny;
        x = nx;
    }
}

// void print_fireballs() {
//     cout << "======================================================\n";
//     cout << "fireball 개수 현황\n";
//     for(int i = 1; i <= N; i++) {
//         for(int j = 1; j <= N; j++)
//             cout << fireballs[i][j].size() << " ";
//         cout << "\n";
//     }
//     cout << "======================================================\n";
// }

//  모든 파이어볼이 한번 이동
void move_fireballs() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int n = fireballs[i][j].size();

            for(int k = 0; k < n; k++) {
                int cy = i, cx = j;
                int cm = fireballs[i][j][k].first.first;
                int cs = fireballs[i][j][k].first.second;
                int cd = fireballs[i][j][k].second;
                int ny, nx, nm = cm, ns = cs, nd = cd;

                move(cy, cx, cs, cd, ny, nx);
                tmp[ny][nx].push_back(make_pair(make_pair(nm, ns), nd));
            }
        }
    }

    tmp.swap(fireballs);
    reset();
}

//  방향이 모두 홀수거나 짝수면 true, 아니면 false
bool all_odd_edge(int y, int x) {
    bool ret = true;
    bool prev = (fireballs[y][x][0].second % 2 == 0);

    for(int i = 1; i < fireballs[y][x].size(); i++) {
        bool now = (fireballs[y][x][i].second % 2 == 0);

        if(prev != now) {
            ret = false;
            break;
        }
        
        prev = now;
    }

    return ret;
}

//  파이어볼 합치고 분리하기
void merge_split() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int cnt = fireballs[i][j].size();

            if(cnt < 2) continue;

            int nm = 0, ns = 0; //  4개로 분리될 파이어볼들의 질량, 속도
            
            for(int k = 0; k < cnt; k++) {
                nm += fireballs[i][j][k].first.first;
                ns += fireballs[i][j][k].first.second;
            }

            nm /= 5;
            ns /= cnt;

            if(nm == 0) {   //  4개로 분리된 파이어볼 질량이 0인 경우
                vector<pair<pair<int, int>, int> >().swap(fireballs[i][j]); //  이전 파이어볼 제거
                continue;
            }

            if(all_odd_edge(i, j)) {    //  이전에 있던 파이어볼 방향이 모두 홀수거나 짝수일 경우
                vector<pair<pair<int, int>, int> >().swap(fireballs[i][j]); //  이전 파이어볼 제거
                for(int k = 0; k < 4; k++)
                    fireballs[i][j].push_back(make_pair(make_pair(nm, ns), 2 * k));
            }
            else {
                vector<pair<pair<int, int>, int> >().swap(fireballs[i][j]); //  이전 파이어볼 제거
                for(int k = 0; k < 4; k++)
                    fireballs[i][j].push_back(make_pair(make_pair(nm, ns), 2 * k + 1));
            }
        }
    }
}

//  파이어볼 질량 합
void calc_ans() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 0; k < fireballs[i][j].size(); k++)
                ans += fireballs[i][j][k].first.first;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    fireballs.assign(N + 1, vector<vector<pair<pair<int, int>, int> > >(N + 1, vector<pair<pair<int, int>, int> >()));
    tmp.assign(N + 1, vector<vector<pair<pair<int, int>, int> > >(N + 1, vector<pair<pair<int, int>, int> >()));

    for(int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;

        fireballs[r][c].push_back(make_pair(make_pair(m, s), d));
    }

    // print_fireballs();
    for(int i = 0; i < K; i++) {
        move_fireballs();
        merge_split();
        // print_fireballs();
    }

    calc_ans();
    cout << ans << '\n';

    return 0;
}