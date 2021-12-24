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
        int N;
        cin >> N;
        int max_n = N;
        while (N != 1) {
            if (N % 2 == 0) {
                N /= 2;
            } else {
                N = N * 3 + 1;
                if (max_n < N) {
                    max_n = N;
                }
            }
        }
        cout << max_n << "\n";
    }
    return 0;
}
