#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> indegree;
vector<int> times;
vector<int> complete_t;
vector<vector<int> > graph;

int N;

void topology_sort(vector<vector<int> > graph, vector<int> indegree, vector<int> times, vector<int>& complete_t) {
    queue<int> q;

    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) {
            complete_t[i] = times[i];
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            complete_t[next] = max(complete_t[next], complete_t[now] + times[next]);

            indegree[next] -= 1;
            if(indegree[next] == 0)
                q.push(next);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    indegree.assign(N + 1, 0);
    times.assign(N + 1, 0);
    complete_t.assign(N + 1, 0);
    graph.assign(N + 1, vector<int>());

    for(int i = 1; i <= N; i++) {
        int x = 0;
        cin >> times[i];

        while(true) {
            cin >> x;

            if(x != -1) {
                graph[x].push_back(i);
                indegree[i] += 1;
            }
            else break;
        }
    } 

    for(int i = 1; i <= N; i++) {
        cout << i << " : ";
        for(int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';

    for(int i = 1; i <= N; i++)
        cout << indegree[i] << ' ';
    cout << '\n';

    topology_sort(graph, indegree, times, complete_t);
    // sort(complete_t.begin(), complete_t.end(), greater<int>());

    for(int i = 1; i <= N; i++)
        cout << complete_t[i] << '\n';

    return 0;
}