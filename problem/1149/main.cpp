#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int N;
vector<tuple<short, short, short>> rgb;
vector<int> cache[3];

int solve(int idx, int color) {
    if (idx == N) {
        return 0;
    }
    int& ans = cache[color][idx];
    if (ans > 0) {
        return ans;
    }
    short val;
    switch (color) {
        case 0:
            val = get<0>(rgb[idx]);
            ans = val + min(solve(idx + 1, 1), solve(idx + 1, 2));
            break;
        case 1:
            val = get<1>(rgb[idx]);
            ans = val + min(solve(idx + 1, 0), solve(idx + 1, 2));
            break;
        case 2:
            val = get<2>(rgb[idx]);
            ans = val + min(solve(idx + 1, 0), solve(idx + 1, 1));
            break;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < 3; i++) {
        cache[i].resize(N);
    }
    for (int i = 0; i < N; i++) {
        short r, g, b;
        cin >> r >> g >> b;
        rgb.emplace_back(r, g, b);
    }
    cout << min({solve(0, 0), solve(0, 1), solve(0, 2)}) << "\n";
    return 0;
}
