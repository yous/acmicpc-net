#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool solve(int mid, short M, int L, vector<int>& S, short q) {
    int cur = 0;
    int count = 0;
    for (auto offset : S) {
        if (offset - cur < mid) {
            continue;
        }
        cur = offset;
        count++;
        if (count == q) {
            break;
        }
    }
    if (count < q) {
        return false;
    }
    if (L - cur < mid) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    int L;
    cin >> L;
    vector<int> S(M);
    for (auto& num : S) {
        cin >> num;
    }
    vector<short> Q(N);
    for (auto& num : Q) {
        cin >> num;
    }
    for (auto q : Q) {
        int lo = 1;
        int hi = L - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (solve(mid, M, L, S, q)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << hi << "\n";
    }
    return 0;
}
