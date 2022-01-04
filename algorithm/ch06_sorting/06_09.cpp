#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Fruit {
public:
    string name;
    int score;
    Fruit(string name, int score) {
        this->name = name;
        this->score = score;
    }
};

bool compare(Fruit& f1, Fruit& f2) {
    return f1.score < f2.score;
}

int main(void) {
    int n = 3;
    Fruit fruits[] = {
        Fruit("바나나", 2),
        Fruit("사과", 5),
        Fruit("당근", 3)
    };

    sort(fruits, fruits + n, compare);
    for(int i = 0; i < n; i++)
        cout << "(" << fruits[i].name << ", " << fruits[i].score << ") ";
    cout << '\n';

    return 0;
}