#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M;

vector<vector<int> > graph;

void floyd_warshall(vector<vector<int> >& graph, int N) {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin >> M;

    graph.assign(N + 1, vector<int>());
    for(int i = 0; i < N + 1; i++) {
        graph[i].assign(N + 1, INF);
        graph[i][i] = 0;
    }

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    floyd_warshall(graph, N);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}