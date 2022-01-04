#include <iostream>
#define INF 999999999
using namespace std;

int graph[3][3] = {
    {0, 7, 5},
    {7, 0, INF},
    {5, INF, 0}
};

int main(void) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(graph[i][j] == INF) 
                cout << -1 << ' ';
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}