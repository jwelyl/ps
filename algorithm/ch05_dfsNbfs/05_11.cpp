#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
using namespace std;

int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<vector<int> > graph;

void bfs(int y, int x) {
    queue<pair<int, int> > q;

    q.push(make_pair(y, x));

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M || graph[ny][nx] != 1)
                continue;
            
            if(ny == 0 && nx == 0)
                continue;

            graph[ny][nx] = graph[cur_y][cur_x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    graph.assign(N, vector<int>());

    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < M; j++) 
            graph[i].push_back(input[j] - '0');
    }

    bfs(0, 0);

    cout << graph[N - 1][M - 1] << '\n';
    return 0;
}