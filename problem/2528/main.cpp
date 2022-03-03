#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, L;
    cin >> N >> L;
    short prev_len;
    bool prev_d;
    cin >> prev_len >> prev_d;
    short prev_l = (prev_d ? L - prev_len : 0);
    int time = 0;
    for (int i = 1; i < N; i++) {
        short len;
        bool d;
        cin >> len >> d;
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
