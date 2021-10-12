#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> prices;
short cache[15][10][1 << 15];

short solve(int artist, int price, int mask) {
    short& ans = cache[artist][price][mask];
    if (ans > 0) {
        return ans;
    }
    ans = 1;
    for (int i = 0; i < N; i++) {
        if ((mask & (1 << i)) || price > prices[artist][i] - '0') {
            continue;
        }
        ans = max(ans, static_cast<short>(1 + solve(i, prices[artist][i] - '0', mask | (1 << i))));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    prices.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    cout << solve(0, 0, 1 << 0) << "\n";
    return 0;
}
