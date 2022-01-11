// https://programmers.co.kr/learn/courses/30/lessons/72413
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<vector<int> > graph;

void floyd_warshall(vector<vector<int> >& graph, int n) {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int tmp = (graph[i][k] != INF && graph[k][j] != INF) ? (graph[i][k] + graph[k][j]) : INF;

                graph[i][j] = min(graph[i][j], tmp);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    int answer = 0;

    //  그래프 초기화
    graph.assign(n + 1, vector<int>());
    for(int i = 0; i < n + 1; i++) {
        graph[i].assign(n + 1, INF);
        graph[i][i] = 0;    //  자기 자신으로 거리 = 0
    }

    //  그래프 입력
    for(int i = 0; i < fares.size(); i++) {
        int a, b, cost;
        a = fares[i][0];
        b = fares[i][1];
        cost = fares[i][2];

        graph[a][b] = graph[b][a] = cost;
    }

    floyd_warshall(graph, n);

    //  각자 따로 가는 거리
    answer = (graph[s][a] != INF && graph[s][b] != INF) ? (graph[s][a] + graph[s][b]) : INF;

    for(int i = 1; i <= n; i++) {
        int tmp = graph[s][i];

        //  s->중간 지점 i, i->a, i->b 합한 거리  
        tmp = (tmp != INF && graph[i][a] != INF && graph[i][b] != INF) ? (tmp + graph[i][a] + graph[i][b]) : INF;
        answer = min(answer, tmp);
    }

    return answer;
}