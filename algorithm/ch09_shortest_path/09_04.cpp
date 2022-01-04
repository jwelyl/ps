#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M;
int X, K;
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

    cin >> N >> M;
    
    graph.assign(N + 1, vector<int>());
    for(int i = 0; i < N + 1; i++) {
        graph[i].assign(N + 1, INF);
        graph[i][i] = 0;
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    cin >> X >> K;

    floyd_warshall(graph, N);

    if(graph[1][K] == INF || graph[K][X] == INF)
        cout << -1 << '\n';
    else
        cout << graph[1][K] + graph[K][X] << '\n';
    
    return 0;
}