#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    int T;
    cin >> N >> T;
    vector<pair<short, short>> segments(N);
    short max_lo = -1000;
    int total_d = 0;
    for (auto& [d, s] : segments) {
        cin >> d >> s;
        max_lo = max(max_lo, short(-s));
        total_d += d;
    }
    double lo = max_lo;
    double hi = 1000 + 1.0 * total_d / T;
    while (lo < hi && (hi - lo) > 1e-7) {
        double mid = (lo + hi) / 2;
        double res = 0;
        for (auto [d, s] : segments) {
            res += 1.0 * d / (s + mid);
        }
        if (fabs(T - res) < 1e-7) {
            break;
        }
        if (res > T) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout.precision(7);
    cout << fixed << (lo + hi) / 2 << "\n";
    return 0;
}
