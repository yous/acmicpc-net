#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool solve(string& paper, int offset, size_t sz) {
    if (sz == 1) {
        return true;
    }
    auto mid = sz / 2;
    for (int i = 0; i < mid; i++) {
        if ((paper[offset + i] ^ paper[offset + sz - 1 - i]) != 1) {
            return false;
        }
    }
    return solve(paper, offset, sz / 2) && solve(paper, offset + mid + 1, sz / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        string paper;
        cin >> paper;
        auto sz = paper.size();
        if (solve(paper, 0, sz)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
