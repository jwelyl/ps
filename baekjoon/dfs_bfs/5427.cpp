#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int T, W, H;
int sy, sx;     //  시작 지점
int cnt = 0, ans = -1;
const string FAIL = "IMPOSSIBLE";
vector<vector<char> > graph;
vector<vector<bool> > visit;
vector<pair<int, int> > fire;   //  불 시작 위치 (y, x)

void reset() {
    cnt = 0, ans = -1;
    vector<vector<char> >().swap(graph);
    vector<vector<bool> >().swap(visit);
    vector<pair<int, int> >().swap(fire);
}

bool can_move(int y, int x) {   //  다음 이동할 칸이 곧 불이 번질 칸인지 확인
    bool ret = true;
    // cout << "can_move 시작!\n";
    for(int i = 0; i < 4; i++) {    //  주변 네 칸에 불 '*'이 하나라도 존재할 경우 false
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= H || nx < 0 || nx >= W)
            continue;
        
        if(graph[ny][nx] == '*') {
            ret = false;
            break;
        }
    }
    // cout << "can_move 정상 종료!\n";

    return ret;
}

void bfs() {
    queue<pair<int, int> > q1;      //  '@'
    queue<pair<int, int> > q2;      //  '*'
    int num1 = 0, num2 = 0; //  각각 q1, q2에 한번에 들어간 개수
    visit[sy][sx] = true;
    q1.push(make_pair(sy, sx));
    // cout << "q1에 (" << sy << ", " << sx << ") push\n";
    num1 += 1;

    for(int i = 0; i < fire.size(); i++) {
        visit[fire[i].first][fire[i].second] = true;
        q2.push(make_pair(fire[i].first, fire[i].second));
        // cout << "q2에 (" << fire[i].first << ", " << fire[i].second << ") push\n";
        num2 += 1;
    }

    while(!q1.empty()) {
        int tmp1 = 0, tmp2 = 0; //  각각 q1, q2에 한번에 새로 들어갈 '@', '*'의 수(후에 num1, num2가 됨)
        cnt += 1;
        // cout << "cnt : " << cnt << '\n';
        
        for(int i = 0; i < num1; i++) { //  지난번에 한번에 들어온 num1개만큼의 '@를 빼서 조사
            int cur_my = q1.front().first;
            int cur_mx = q1.front().second;
            q1.pop();

            for(int dir = 0; dir < 4; dir++) {
                int n_my = cur_my + dy[dir];
                int n_mx = cur_mx + dx[dir];

                if(n_my < 0 || n_my >= H || n_mx < 0 || n_mx >= W) {    //  건물 밖으로 탈출 가능한 경우
                    ans = cnt;
                    return;
                }
                
                if(graph[n_my][n_mx] == '.' && !visit[n_my][n_mx]) {  //  아직 이동하지 않은 빈 칸일 경우
                    if(can_move(n_my, n_mx)) {  //  해당 칸으로 불이 번지지 않을 경우
                        visit[n_my][n_mx] = true;
                        graph[n_my][n_mx] = '@';
                        q1.push(make_pair(n_my, n_mx));
                        // cout << "q1에 (" << n_my << ", " << n_mx << ") push\n";
                        tmp1 += 1;
                    }
                }
            }
        }

        for(int i = 0; i < num2; i++) { //  지난 번에 한번에 들어온 num2의 개수만큼 '*'을 조사
            int cur_fy = q2.front().first;
            int cur_fx = q2.front().second;
            q2.pop();

            for(int dir = 0; dir < 4; dir++) {
                int n_fy = cur_fy + dy[dir];
                int n_fx = cur_fx + dx[dir];

                if(n_fy < 0 || n_fy >= H || n_fx < 0 || n_fx >= W)
                    continue;
                if(graph[n_fy][n_fx] == '#' || graph[n_fy][n_fx] == '*')
                    continue;
                
                graph[n_fy][n_fx] = '*';
                q2.push(make_pair(n_fy, n_fx));
                // cout << "q2에 (" << n_fy << ", " << n_fx << ") push\n";
                tmp2 += 1;
            }
        }

        num1 = tmp1;
        num2 = tmp2;
    }
    
    ans = -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for(int t = 0; t < T; t++) {
        reset();
        cin >> W >> H;
        cin.ignore();
        graph.assign(H, vector<char>());
        visit.assign(H, vector<bool>());

        for(int i = 0; i < H; i++) {
            graph[i].assign(W, ' ');
            visit[i].assign(W, false);
        }

        //  그래프 입력
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> graph[i][j];

                if(graph[i][j] == '@') {    //  시작 위치일 경우
                    sy = i;
                    sx = j;
                }
                else if(graph[i][j] == '*')
                    fire.push_back(make_pair(i, j));
            }
        }

        bfs();
    
        if(ans == -1)
            cout << FAIL << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}
