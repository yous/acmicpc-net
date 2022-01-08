#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<short> cache;

bool solve(int n) {
    short& ans = cache[n - 1];
    if (ans > 0) {
        return ans == 1;
    }
    if (solve(n - 1) && solve(n - 3) && solve(n - 4)) {
        ans = 2;
        return false;
    }
    ans = 1;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    if (N <= 4) {
        cout << (N == 2 ? "CY\n" : "SK\n");
        return 0;
    }
    cache.resize(N);
    cache[0] = 1;
    cache[1] = 2;
    cache[2] = 1;
    cache[3] = 1;
    cout << (solve(N) ? "SK\n" : "CY\n");
    return 0;
}
