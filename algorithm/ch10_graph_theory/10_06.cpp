#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
vector<vector<int> > graph;
vector<int> indegree;
vector<int> result;

void topology_sort(vector<vector<int> > graph, vector<int> indegree, vector<int>& result) {
    queue<int> q;

    for(int i = 1; i <= V; i++) {
        if(indegree[i] == 0) 
            q.push(i);
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        result.push_back(now);

        for(int i = 0; i < graph[now].size(); i++) {
            indegree[graph[now][i]] -= 1;

            if(indegree[graph[now][i]] == 0) 
                q.push(graph[now][i]);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;

    graph.assign(V + 1, vector<int>());
    indegree.assign(V + 1, 0);

    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;

        indegree[b] += 1;
        graph[a].push_back(b);
    }

    // for(int i = 1; i <= V; i++) {
    //     cout << i << " : ";
    //     for(int j = 0; j < graph[i].size(); j++)
    //         cout << graph[i][j] << " ";
    //     cout << '\n';
    // }

    // cout << "initial indegree\n";
    // for(int i = 1; i < indegree.size(); i++)
    //     cout << indegree[i] << ' ';
    // cout << '\n';

    topology_sort(graph, indegree, result);

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
    cout << '\n';

    return 0;
}