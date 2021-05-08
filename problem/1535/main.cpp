#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int hp[20];
int happy[20];
vector<int> selected;
int max_happy = 0;

void solve(int cur_hp, int cur_happy, int index) {
    if (index >= N) {
        if (cur_happy > max_happy) {
            max_happy = cur_happy;
        }
        return;
    }
    if (cur_hp > hp[index]) {
        solve(cur_hp - hp[index], cur_happy + happy[index], index + 1);
    }
    solve(cur_hp, cur_happy, index + 1);
}

int main() {
    int i;
    cin >> N;
    for (i = 0; i < N; i++) {
        int num;
        cin >> num;
        hp[i] = num;
    }
    for (i = 0; i < N; i++) {
        int num;
        cin >> num;
        happy[i] = num;
    }
    solve(100, 0, 0);
    cout << max_happy << "\n";
    return 0;
}
