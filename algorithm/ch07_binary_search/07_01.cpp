#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, idx;
string target;
vector<string> arr;

int sequential_search(int n, string target, vector<string> arr) {
    int ret = -1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) {
            ret =  i + 1;
            break;
        }
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> target;

    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        arr.push_back(input);
    }

    idx = sequential_search(N, target, arr);
    cout << idx << '\n';
    return 0;
}