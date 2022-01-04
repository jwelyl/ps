#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;

class Student {
public:
    string name;
    int score;

    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }
};

vector<Student> arr;

bool comp(Student& s1, Student& s2) {
    return (s1.score < s2.score);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for(int i = 0; i < N; i++) {
        string name;
        int score;

        cin >> name >> score;
        arr.push_back(Student(name, score));
    }

    sort(arr.begin(), arr.end(), comp);

    for(int i = 0; i < arr.size(); i++)
        cout << arr[i].name << ' ';
    cout << '\n';

    return 0;
}
