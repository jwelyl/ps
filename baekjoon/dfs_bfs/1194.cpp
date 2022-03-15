#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define KEY    (1 << 6)
using namespace std;

int N, M;       //  맵 크기
int sy, sx, sk; //  시작 위치
int ans = -1;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

vector<vector<char> > graph;
vector<vector<bool> > visited[KEY];

void bfs() {
    queue<pair<pair<int, int>, pair<int, int> > > q;    //  (y, x, key, cnt)
    visited[sk][sy][sx] = true;
    q.push(make_pair(make_pair(sy, sx), make_pair(sk, 0)));
    // cout << "In bfs\n";

    while(!q.empty()) {
        // cout << "In while\n";
        int cur_y = q.front().first.first;      //  현재 y 좌표
        int cur_x = q.front().first.second;     //  현재 x 좌표
        int cur_k = q.front().second.first;     //  현재 key
        int cur_n = q.front().second.second;    //  현재까지 움직인 횟수
        q.pop();

        for(int i = 0; i < 4; i++) {
            // cout << "In for\n";
            int n_y = cur_y + dy[i];    //  다음 y 좌표
            int n_x = cur_x + dx[i];    //  다음 x 좌표
            int n_k;                    //  다음 key
            int n_n = cur_n + 1;        //  다음 칸으로 이동했을 때 움직인 횟수
            int mask;

            //  주변 칸이 범위를 벗어나거나 벽일 경우, 또는 현재 키로 이미 방문한 경우, 다른 칸을 탐색
            if(n_y < 0 || n_y >= N || n_x < 0 || n_x >= M || graph[n_y][n_x] == '#' || visited[cur_k][n_y][n_x])
                continue;
            else if('a' <= graph[n_y][n_x] && graph[n_y][n_x] <= 'f') { //  열쇠일 경우
                mask = (1 << (graph[n_y][n_x] - 'a'));
                n_k = (cur_k | mask); //  새로 획득한 key 추가
            }
            else if('A' <= graph[n_y][n_x] && graph[n_y][n_x] <= 'F') { //  문일 경우
                mask = (1 << (graph[n_y][n_x] - 'A'));  //  문
                n_k = cur_k;

                if((n_k & mask) == 0) //  문에 해당하는 key가 없을 경우
                    continue;
            }
            else if(graph[n_y][n_x] == '1') {   //  출구일 경우
                ans = n_n;
                return;
            }
            else   //  빈 칸일 경우
                n_k = cur_k;

            visited[n_k][n_y][n_x] = true;
            q.push(make_pair(make_pair(n_y, n_x), make_pair(n_k, n_n)));
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cout << KEY << '\n';
    
    //  맵 할당
    cin >> N >> M;
    cin.ignore();
    graph.assign(N, vector<char>());
    for(int i = 0; i < N; i++)
        graph[i].assign(M, '.');
    for(int i = 0; i < KEY; i++) {
        visited[i].assign(N, vector<bool>());
        for(int j = 0; j < N; j++)
            visited[i][j].assign(M, false);
    }

    //  맵 입력
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char ch;
            cin >> ch;

            graph[i][j] = ch;
            if(ch == '0') {
                sy = i;
                sx = j;
                sk = 0; //  처음엔 key 없음
            }
        }
    }

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++)
    //         cout << graph[i][j];
    //     cout << '\n';
    // } 

    // for(int l = 0; l < KEY; l++) {
    //     cout << l << '\n';
    //     for(int i = 0; i < N; i++) {
    //         for(int j = 0; j < M; j++)
    //             cout << visited[l][i][j];
    //         cout << '\n';
    //     } 
    // }
    bfs();
    cout << ans << '\n';

    return 0;
}