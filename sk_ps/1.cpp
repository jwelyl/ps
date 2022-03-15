#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 1000001

using namespace std;

int coins[6] = {1, 5, 10, 50, 100, 500};
bool used[6] = {false, };
int leftmoney = 0;   //  만들어야 할 잔여 금액

int solution(int money, vector<int> costs) {
    int answer = 0;
    leftmoney = money;
    cout << "leftmoney = " << leftmoney << '\n';

    while(leftmoney > 0) {
        int min_cost = MAX; //  현재 잔여 화폐 중에서 동전을 만들 때 최소 비용
        int min_q = -1;     //  그 때 만든 동전의 개수
        int min_i = -1;     //  동전의 index
        cout << "-------------------------------------------------------------\n";
        for(int i = 5; i >= 0; i--) {
            int q = leftmoney / coins[i];
            int cost = (q > 0) ? (costs[i] * q) : MAX;

            cout << "현재 잔여 금액 : " << leftmoney << '\n';
            cout << "현재 화폐 " << coins[i] << "로 만들 시 드는 비용 : " << cost << '\n';

            if(min_cost > cost) {
                min_cost = cost;
                min_q = q;
                min_i = i;
            }
        }
        cout << "현재 동전을 만드는 최소 비용 : " << min_cost << '\n';

        answer += min_cost;
        leftmoney -= (coins[min_i] * min_q);
    }

    return answer;
}