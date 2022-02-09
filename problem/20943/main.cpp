#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    map<pair<int, int>, int> ma;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < 0) {
            a = -a;
            b = -b;
        }
        if (a == 0) {
            b = 1;
        } else if (b == 0) {
            a = 1;
        }
        int g = gcd(a, abs(b));
        ma[make_pair(a / g, b / g)]++;
    }
    long long ans = 1LL * N * (N - 1) / 2;
    for (auto [k, v] : ma) {
        if (v > 1) {
            ans -= 1LL * v * (v - 1) / 2;
        }
    }
    cout << ans << "\n";
    return 0;
}
