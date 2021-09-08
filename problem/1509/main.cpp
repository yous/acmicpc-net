#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S;
int sz;
vector<int> palin_odd;
vector<int> palin_even;
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
    for (int i = 2; i < sz - idx; i += 2) {
        if (palin_odd[idx + i / 2] >= 1 + i / 2) {
            ans = min(ans, 1 + solve(idx + i + 1));
        }
    }
    for (int i = 1; i < sz - idx; i += 2) {
        if (palin_even[idx + i / 2] >= 1 + i / 2) {
            ans = min(ans, 1 + solve(idx + i + 1));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    sz = S.size();
    for (int i = 0; i < sz; i++) {
        int lo = i;
        int hi = i;
        int cnt = 0;
        while (lo >= 0 && hi < sz && S[lo] == S[hi]) {
            cnt++;
            lo--;
            hi++;
        }
        palin_odd.push_back(cnt);
    }
    for (int i = 0; i < sz - 1; i++) {
        int lo = i;
        int hi = i + 1;
        int cnt = 0;
        while (lo >= 0 && hi < sz && S[lo] == S[hi]) {
            cnt++;
            lo--;
            hi++;
        }
        palin_even.push_back(cnt);
    }
    cache.resize(sz);
    cout << solve(0) << "\n";
    return 0;
}
