#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 1e9;
int N;
vector<tuple<short, short, short>> houses;

int solve(int idx) {
    int sel_r, sel_g, sel_b;
    int prev_r = INF,
        prev_g = INF,
        prev_b = INF;
    switch (idx) {
        case 0:
            prev_r = get<0>(houses[0]);
            break;
        case 1:
            prev_g = get<1>(houses[0]);
            break;
        case 2:
            prev_b = get<2>(houses[0]);
            break;
    }
    for (int i = 1; i < N; i++) {
        sel_r = min(prev_g, prev_b) + get<0>(houses[i]);
        sel_g = min(prev_r, prev_b) + get<1>(houses[i]);
        sel_b = min(prev_r, prev_g) + get<2>(houses[i]);
        prev_r = sel_r;
        prev_g = sel_g;
        prev_b = sel_b;
    }
    switch (idx) {
        case 0:
            return min(sel_g, sel_b);
        case 1:
            return min(sel_r, sel_b);
        case 2:
            return min(sel_r, sel_g);
    }
    return INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        short r, g, b;
        cin >> r >> g >> b;
        houses.emplace_back(r, g, b);
    }
    cout << min({solve(0), solve(1), solve(2)}) << "\n";
    return 0;
}
