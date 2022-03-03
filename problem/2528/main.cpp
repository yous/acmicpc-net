#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, L;
    cin >> N >> L;
    short prev_l;
    bool prev_d;
    cin >> prev_l >> prev_d;
    short max_diff = 0;
    for (int i = 1; i < N; i++) {
        short l;
        bool d;
        cin >> l >> d;
        if (prev_d != d) {
            short diff = L - (prev_l + l);
            if (max_diff < diff) {
                max_diff = diff;
            }
        }
        prev_l = l;
        prev_d = d;
    }
    cout << max_diff / 2 << "\n";
    return 0;
}
