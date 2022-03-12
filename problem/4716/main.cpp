#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, A, B;
    while (cin >> N >> A >> B) {
        if (N == 0 && A == 0 && B == 0) {
            break;
        }
        vector<tuple<short, short, short>> teams(N);
        for (auto& [k, da, db] : teams) {
            cin >> k >> da >> db;
        }
        sort(teams.begin(), teams.end(), [&](const tuple<short, short, short>& lhs, const tuple<short, short, short>& rhs) {
            return abs(get<2>(lhs) - get<1>(lhs)) > abs(get<2>(rhs) - get<1>(rhs));
        });
        int ans = 0;
        for (auto [k, da, db] : teams) {
            if (da <= db) {
                if (A >= k) {
                    ans += k * da;
                    A -= k;
                } else {
                    ans += A * da;
                    ans += (k - A) * db;
                    B -= k - A;
                    A = 0;
                }
            } else {
                if (B >= k) {
                    ans += k * db;
                    B -= k;
                } else {
                    ans += B * db;
                    ans += (k - B) * da;
                    A -= k - B;
                    B = 0;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
