#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, Q;
vector<int> P;
vector<int> inv_P;

int solve(int loc) {
    int start = min(loc, N - M);
    int ans = loc;
    while (start >= 0) {
        ans = start + inv_P[ans - start];
        if (ans >= start + M - 1) {
            break;
        }
        start--;
    }
    return ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> Q;
    inv_P.resize(M);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        P.push_back(num - 1);
        inv_P[num - 1] = i;
    }
    for (int i = 0; i < Q; i++) {
        int num;
        cin >> num;
        cout << solve(N - num) << "\n";
    }
    return 0;
}
