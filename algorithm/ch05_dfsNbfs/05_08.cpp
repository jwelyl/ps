#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[9];
bool visited[9] = {false, };

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";

    for(int i = 0; i < graph[v].size(); i++) {
        int next = graph[v][i];

        if(!visited[next])
            dfs(next);
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

    dfs(1);
    cout << '\n';

    return 0;
}


