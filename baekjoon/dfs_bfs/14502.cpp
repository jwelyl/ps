#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

vector<pair<int, int> > virus;

int N, M;
int ans = 0;
vector<vector<int> > graph;
vector<vector<int> > copied;

void ret_idx(int num, int& y, int& x) { //  num번째 칸의 index 구하기
    y = num / M;
    x = num % M;
}

void copy_graph() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            copied[i][j] = graph[i][j];
}

int safe_zone(vector<vector<int> > g) {
    int ret = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(g[i][j] == 0)
                ret += 1;
        }
    }

    return ret;
}

int bfs() {
    queue<pair<int, int> > q;
    int n = 0;  //  한번에 queue에 들어가는 2의 개수

    copy_graph();
    for(int i = 0; i < virus.size(); i++) {
        n++;
        q.push(make_pair(virus[i].first, virus[i].second));
    }

    while(!q.empty()) {
        int tmp = 0;    //  한번에 queue에 들어가는 2의 개수(후에 n이 됨)

        for(int i = 0; i < n; i++) {
            int cur_y = q.front().first;
            int cur_x = q.front().second;
            q.pop();

            for(int d = 0; d < 4; d++) {
                int ny = cur_y + dy[d];
                int nx = cur_x + dx[d];

                if(ny < 0 || ny >= N || nx < 0 || nx >= M || copied[ny][nx] != 0)
                    continue;
                
                q.push(make_pair(ny, nx));
                copied[ny][nx] = 2;
                tmp++;
            }
        }

        n = tmp;
    }

    return safe_zone(copied);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    cin >> N >> M;

    graph.assign(N, vector<int>());
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int x;
            cin >> x;
            graph[i].push_back(x);

            if(x == 2)
                virus.push_back(make_pair(i, j));
        }
    }
    copied.assign(N, vector<int>(M, 0));

    for(int i = 0; i < N * M - 2; i++) {    //  첫 번째 벽
        int y1, x1;
        ret_idx(i, y1, x1);

        if(graph[y1][x1] != 0) continue;
        graph[y1][x1] = 1;  //  첫 번째 벽을 설치

        for(int j = i + 1; j < N * M - 1; j++) {    //  두 번째 벽
            int y2, x2;
            ret_idx(j, y2, x2);

            if(graph[y2][x2] != 0) continue;
            graph[y2][x2] = 1;  //  두 번째 벽을 설치

            for(int k = j + 1; k < N * M; k++) {    //  세 번째 벽
                int y3, x3;
                ret_idx(k, y3, x3);

                if(graph[y3][x3] != 0) continue;
                graph[y3][x3] = 1;  //  세 번째 벽을 설치
                ans = max(ans, bfs());
                graph[y3][x3] = 0;  //  벽 다시 허뭄(다음 벽 설치 위해)
            }
            graph[y2][x2] = 0;
        }
        graph[y1][x1] = 0;
    }

    cout << ans << '\n';

    return 0;
}