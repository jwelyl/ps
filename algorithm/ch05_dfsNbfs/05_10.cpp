#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
int sol;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<vector<char> > graph;
// vector<vector<bool> > visited;

void dfs(int y, int x) {
    // visited[y][x] = true;
    graph[y][x] = '1';

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        // if(graph[ny][nx] == '0' && !visited[ny][nx])
        if(graph[ny][nx] == '0')
            dfs(ny, nx);
    }
}

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        // visited[cur_y][cur_x] = true;
        graph[cur_y][cur_x] = '1';

        for(int i = 0; i < 4; i++) {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            // if(graph[ny][nx] == '0' && !visited[ny][nx])
            if(graph[ny][nx] == '0')
                q.push(make_pair(ny, nx));
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    graph.assign(N, vector<char>());
    // visited.assign(N, vector<bool>());

    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;

        // visited[i].assign(M, false);

        for(int j = 0; j < input.size(); j++)
            graph[i].push_back(input[j]);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            // if(graph[i][j] == '0' && !visited[i][j]) {
            if(graph[i][j] == '0') {
                sol++;
                dfs(i, j);
                // bfs(i, j);
            }
        }
    }

    cout << sol << '\n';

    return 0;
}