#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        int R, C;
        cin >> R >> C;
        if (R > C) {
            swap(R, C);
        }
        /*
        while (R > 0 && C > 0) {
            white_cnt += 1LL * R * C;
            black_cnt += 1LL * (R - 1) * C;
            black_cnt += 1LL * R * (C - 1);
            white_cnt += 1LL * (R - 1) * (C - 1);
            R--;
            C--;
        }
        white = n * (n - R + C) + (n - 1) * (n - R + C - 1)
              = 2n^2 - 2(R - C + 1)n + (R - C + 1);
        black = (n - 1) * (n - R + C) + n * (n - R + C - 1)
              = 2n^2 - 2(R - C + 1)n + R - C
        */
        long long white_cnt = 1LL * R * (R + 1) * (2 * R + 1) / 6 * 2;
        white_cnt -= 1LL * R * (R + 1) / 2 * 2 * (R - C + 1);
        white_cnt += 1LL * R * (R - C + 1);
        long long black_cnt = 1LL * R * (R + 1) * (2 * R + 1) / 6 * 2;
        black_cnt -= 1LL * R * (R + 1) / 2 * 2 * (R - C + 1);
        black_cnt += 1LL * R * (R - C);
        cout << white_cnt << " " << black_cnt << "\n";
    }
    return 0;
}
