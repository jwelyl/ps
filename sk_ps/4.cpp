#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<vector<pair<int, int> > > tree;

long long solution(int n, vector<vector<int> > edges) {
    long long answer = 0;
    tree.assign(n, vector<pair<int, int> >());

    for(int i = 0; i < edges.size(); i++) {
        tree[edges[i][0]].push_back(make_pair(edges[i][1], 1));
        tree[edges[i][1]].push_back(make_pair(edges[i][0], 1));
    }

    return answer;
}