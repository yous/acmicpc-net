#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> rows(N);
    vector<int> cols(M);
    for (int i = 0; i < Q; i++) {
        short cmd;
        int r, c;
        short v;
        cin >> cmd;
        if (cmd == 1) {
            cin >> r >> v;
            rows[r - 1] += v;
        } else {
            cin >> c >> v;
            cols[c - 1] += v;
        }
    }
    for (int i = 0; i < N; i++) {
        int row_val = rows[i];
        cout << row_val + cols[0];
        for (int j = 1; j < M; j++) {
            cout << " " << row_val + cols[j];
        }
        cout << "\n";
    }
    return 0;
}
