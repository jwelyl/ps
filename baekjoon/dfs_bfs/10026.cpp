#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
 
int N;
int normal = 0, abnormal = 0;

vector<vector<char> > graph;
vector<vector<bool> > visited;

void reset() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            visited[i][j] = false;
}

void bfs(int y, int x, bool ok) {
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visited[y][x] = true;

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        char cur_c = graph[cur_y][cur_x];
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            char nc;

            if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
                continue;

            nc = graph[ny][nx];
            if(ok) {    //  정상인일 경우
                if(cur_c == nc) {
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
            else {  //  적록색약일 경우
                if((cur_c == 'B' && nc == 'B') || (cur_c != 'B' && nc != 'B')) {
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx)); 
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin.ignore();
    graph.assign(N, vector<char>());
    visited.assign(N, vector<bool>());

    for(int i = 0; i < N; i++) {
        graph[i].assign(N, ' ');
        visited[i].assign(N, false);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cin >> graph[i][j];
    }

    //  정상인의 경우
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                bfs(i, j, true);
                normal += 1;
            }
        }
    }

    reset();    //  visited 초기화

    //  적록색약의 경우
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                bfs(i, j, false);
                abnormal += 1;
            }
        }
    }

    cout << normal << " " << abnormal << '\n';
    return 0;
}