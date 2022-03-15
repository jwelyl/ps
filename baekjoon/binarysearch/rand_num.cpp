#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;

int main(void) {
    srand(time(NULL));
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) 
        nums.push_back(rand() % M + 1);
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}