#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    vector<short> row(M);
    short ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> row[j];
        }
        short grundy = row[M - 1];
        for (int j = M - 2; j >= 0; j--) {
            short num = row[j];
            if (num > grundy) {
                grundy = num;
            } else {
                grundy = num - 1;
            }
        }
        ans ^= grundy;
    }
    cout << (ans == 0 ? "cubelover\n" : "koosaga\n");
    return 0;
}
