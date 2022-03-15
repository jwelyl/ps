#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define NONE       0
#define RED        1
#define BLACK     -1
using namespace std;

int K, V, E;
vector<vector<int> > graph;
vector<int> colors;
vector<int> components; //  graph의 각 connected componet의 첫 번째 vertex 저장

void dfs(int v) {
    colors[v] = RED;

    for(int i = 0; i < graph[v].size(); i++) {
        int w = graph[v][i];

        if(colors[w] == NONE)
            dfs(w);
    }
}

bool bfs(int num) {
    queue<pair<int, int> > q;
    colors[num] = RED;
    q.push(make_pair(num, colors[num]));

    while(!q.empty()) {
        int curv = q.front().first;
        int curc = q.front().second;
        q.pop();

        for(int i = 0; i < graph[curv].size(); i++) {
            int nv = graph[curv][i];

            if(colors[nv] == NONE) {                    //  인접 정점을 아직 방문하지 않은 경우
                colors[nv] = (NONE - curc);             //  인접 정점을 다른 색으로 설정
                q.push(make_pair(nv, colors[nv]));
            }
            else if(colors[nv] == curc) //  인접 정점을 이미 방문한적 있는데 현재 정점과 같은 색으로 칠해진 경우
                return false;
        }
    }

    return true;
}

void reset() {
    vector<vector<int> >().swap(graph);
    vector<int>().swap(colors);
    vector<int>().swap(components);
}

void reset_colors() {
    for(int i = 0; i < colors.size(); i++)
        colors[i] = NONE;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    for(int tc = 0; tc < K; tc++) {
        bool bpg = true;    //  이분그래프일 경우 true, 아닐 경우 false;

        cin >> V >> E;
        graph.assign(V + 1, vector<int>());
        colors.assign(V + 1, NONE);

        for(int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 1; i <= V; i++) {
            if(colors[i] == NONE) {
                components.push_back(i);
                dfs(i);
            }
        }
        reset_colors();

        for(int i = 0; i < components.size(); i++) {
            if(!bfs(components[i])) {
                bpg = false;
                break;
            }
        }
        if(bpg)
            cout << "YES\n";
        else
            cout << "NO\n";
        reset();
    }

    return 0;
}