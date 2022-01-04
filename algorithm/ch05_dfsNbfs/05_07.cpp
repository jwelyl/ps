#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<pair<int, int> > > graph;

int main(void) {
    graph.assign(3, vector<pair<int, int> >());
    graph[0].push_back(make_pair(1, 7));
    graph[0].push_back(make_pair(2, 5));
    graph[1].push_back(make_pair(0, 7));
    graph[2].push_back(make_pair(0, 5));

    for(int i = 0; i < 3; i++) {
        cout << i << " : ";
        for(int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j].first << "(" << graph[i][j].second << ")";
            if(j != graph[i].size() - 1) cout << " -> ";
        }
        cout << '\n';
    }

    return 0;
}