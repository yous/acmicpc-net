#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S;
int sz;
vector<int> cache;

int solve(int idx) {
    if (idx == sz) {
        return 0;
    }
    int& ans = cache[idx];
    if (ans > 0) {
        return ans;
    }
    ans = 1 + solve(idx + 1);
    for (int i = idx + 1; i < sz; i++) {
        int lo = idx;
        int hi = i;
        bool found = true;
        while (lo < hi) {
            if (S[lo] != S[hi]) {
                found = false;
                break;
            }
            lo++;
            hi--;
        }
        if (found) {
            ans = min(ans, 1 + solve(i + 1));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    sz = S.size();
    cache.resize(sz);
    cout << solve(0) << "\n";
    return 0;
}
