#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, L;
    cin >> N >> L;
    vector<pair<short, bool>> sticks(N);
    for (auto& [l, d] : sticks) {
        cin >> l >> d;
    }
    auto [prev_len, prev_d] = sticks[0];
    short prev_l = (prev_d ? L - prev_len : 0);
    int time = 0;
    for (int i = 1; i < N; i++) {
        auto [len, d] = sticks[i];
        short l = (d ? L - len : 0);
        int rem = (L > len ? time % (2 * (L - len)) : 0);
        if (rem <= L - len) {
            l += (d ? -rem : rem);
        } else {
            rem -= L - len;
            l = (d ? rem : L - len - rem);
        }
        while (prev_l + prev_len < l || l + len < prev_l) {
            time++;
            if (prev_d) {
                prev_l--;
                if (prev_l == 0) {
                    prev_d = !prev_d;
                }
            } else {
                prev_l++;
                if (prev_l == L - prev_len) {
                    prev_d = !prev_d;
                }
            }
            if (d) {
                l--;
                if (l == 0) {
                    d = !d;
                }
            } else {
                l++;
                if (l == L - len) {
                    d = !d;
                }
            }
        }
        prev_len = len;
        prev_d = d;
        prev_l = l;
    }
    cout << time << "\n";
    return 0;
}
