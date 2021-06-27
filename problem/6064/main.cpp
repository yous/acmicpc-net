#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int M, N, X, Y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> M >> N >> X >> Y;
        if (X == Y) {
            cout << X << "\n";
            continue;
        }
        if (M == N) {
            cout << "-1\n";
        } else {
            if (M > N) {
                swap(M, N);
                swap(X, Y);
            }
            int dist_diff = Y - X;
            if (dist_diff < 0) {
                dist_diff += N;
            }
            int m = 1;
            int n = M % N + 1;
            int year = 1 + M;
            bool found = false;
            while (m != 1 || n != 1) {
                if (n - m == dist_diff) {
                    found = true;
                    cout << year + X - m << "\n";
                    break;
                }
                if (found) {
                    break;
                }
                n = (n + M - 1) % N + 1;
                year += M;
            }
            if (!found) {
                cout << "-1\n";
            }
        }
    }
    return 0;
}
