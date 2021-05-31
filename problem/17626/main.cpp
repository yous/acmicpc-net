#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
short squares[50001];

short solve(int n) {
    if (n == 0) {
        return 0;
    }
    if (squares[n] != 0) {
        return squares[n];
    }
    short ans = 4;
    for (int i = 1; i * i <= n; i++) {
        ans = min(ans, static_cast<short>(1 + solve(n - i * i)));
    }
    squares[n] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cout << solve(N) << "\n";
    return 0;
}
