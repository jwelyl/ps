#include <iostream>
#include <vector>
using namespace std;

int N, M;
int ypos, xpos, look;
int sol = 1;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<vector<int> > field;
vector<vector<bool> > visited;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    field.assign(N, vector<int>());
    visited.assign(N, vector<bool>());

    for(int i = 0; i < N; i++) {
        visited[i].assign(M, false);
        for(int j = 0; j < M; j++) {
            int x;
            cin >> x;
            field[i].push_back(x);
        }
    }

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++)
    //         cout << field[i][j] << ' ';
    //     cout << '\n';
    // }

    cin >> ypos >> xpos >> look;
    visited[ypos][xpos] = true;

    while(true) {
        int ny, nx;
        bool moved = false;

        for(int i = 0; i < 4; i++) {
            ny = ypos + dy[look];
            nx = xpos + dx[look];
            // cout << "ny : " << ny << '\n';
            // cout << "nx : " << nx << '\n';

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) {
                look = (look + 1) % 4;
                continue;
            }

            if(field[ny][nx] != 1 && !visited[ny][nx]) {
                sol++;
                visited[ny][nx] = true;
                moved = true;

                ypos = ny;
                xpos = nx;

                break;
            }

            look = (look + 1) % 4;

            // cout << '\n';
        }

        if(!moved) {
            ny = xpos - dx[look];
            nx = ypos - dy[look];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M || field[ny][nx] == 1) break;

            ypos = ny;
            xpos = nx;
        }
    }

    cout << sol << '\n';

    return 0;
}



