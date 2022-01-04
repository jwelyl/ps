#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999999
using namespace std;

int arr[] = {7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2};
vector<int> cnt;

int main(void) {
    int max_num = -INF;

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
        if(max_num < arr[i]) max_num = arr[i];

    cnt.assign(max_num + 1, 0);

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++) 
        cnt[arr[i]] += 1;

    for(int i = 0; i < cnt.size(); i++) {
        for(int j = 0; j < cnt[i]; j++)
            cout << i << " ";
    }
    cout << '\n';
    
    return 0;
}