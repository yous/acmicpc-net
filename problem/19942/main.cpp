#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

short N;
array<short, 4> min_ingrs;
vector<array<short, 5>> foods;
short min_cost;
int ans_mask = -1;

void solve(int idx, array<short, 5>& cur, int mask) {
    bool found = true;
    for (int i = 0; i < 4; i++) {
        if (cur[i] < min_ingrs[i]) {
            found = false;
            break;
        }
    }
    if (found) {
        if (min_cost > cur[4]) {
            min_cost = cur[4];
            ans_mask = mask;
        }
        return;
    }
    if (idx >= N) {
        return;
    }
    for (int i = 0; i < 5; i++) {
        cur[i] += foods[idx][i];
    }
    solve(idx + 1, cur, mask | (1 << idx));
    for (int i = 0; i < 5; i++) {
        cur[i] -= foods[idx][i];
    }
    solve(idx + 1, cur, mask);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    foods.resize(N);
    for (auto& min_ingr : min_ingrs) {
        cin >> min_ingr;
    }
    for (auto& food : foods) {
        for (auto& ingr : food) {
            cin >> ingr;
        }
    }
    min_cost = N * 500;
    array<short, 5> cur = {0, 0, 0, 0, 0};
    solve(0, cur, 0);
    if (ans_mask == -1) {
        cout << "-1\n";
    } else {
        cout << min_cost << "\n";
        bool first = true;
        for (int i = 0; i < N; i++) {
            if ((ans_mask & (1 << i)) == 0) {
                continue;
            }
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << (i + 1);
        }
        cout << "\n";
    }
    return 0;
}
