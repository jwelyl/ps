#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[9];
bool visited[9] = {false, };

void bfs(int v) {
    queue<int> q;

    visited[v] = true;
    q.push(v);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for(int i = 0; i < graph[cur].size(); i++) {
            if(!visited[graph[cur][i]]) {
                visited[graph[cur][i]] = true;
                q.push(graph[cur][i]);
            }
        }
    }
}

int main(void) {
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    graph[2].push_back(1);
    graph[2].push_back(7);
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(3);
    graph[5].push_back(4);
    graph[6].push_back(7);
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    graph[8].push_back(1);
    graph[8].push_back(7);

    bfs(1);
    cout << '\n';

    return 0;
}


