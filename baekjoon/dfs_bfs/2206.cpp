#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define KEY       2
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int N, M;
vector<vector<char> > graph;
vector<vector<bool> > visited[KEY];

int bfs() {
    queue<pair<pair<int, int>, pair<int, int> > > q;    //  ((y, x), (n, k))
    visited[1][0][0] = true;
    q.push(make_pair(make_pair(0, 0), make_pair(1, 1)));

    while(!q.empty()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int cn = q.front().second.first;
        int ck = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int nn = cn + 1;
            int nk = ck;

            if(ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            
            if(visited[nk][ny][nx])
                continue;

            if(graph[ny][nx] == '0') {    //  벽이 아닐 경우
                q.push(make_pair(make_pair(ny, nx), make_pair(nn, nk)));
                visited[nk][ny][nx] = true;

                if(ny == N - 1 && nx == M - 1)
                    return nn;
            }
            else {  //  벽일 경우
                if(nk > 0) {
                    nk -= 1;
                    q.push(make_pair(make_pair(ny, nx), make_pair(nn, nk)));
                    visited[nk][ny][nx] = true;
                }
                else continue;
            }
        }
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    cin.ignore();

    graph.assign(N, vector<char>(M, 0));
    for(int i = 0; i < KEY; i++)
        visited[i].assign(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            cin >> graph[i][j];
    }
    if(N == 1 && M == 1)
        cout << 1 << '\n';
    else
        cout << bfs() << '\n';

    return 0;
}