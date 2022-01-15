#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N_sz;
vector<vector<int>> cache;

int solve(string& n, int k) {
    if (k == 0) {
        return stoi(n);
    }
    int& ans = cache[stoi(n)][k - 1];
    if (ans > 0) {
        return ans;
    }
    for (int j = 1; j < N_sz; j++) {
        if (n[j] == '0') {
            continue;
        }
        swap(n[0], n[j]);
        ans = max(ans, solve(n, k - 1));
        swap(n[0], n[j]);
    }
    for (int i = 1; i < N_sz - 1; i++) {
        for (int j = i + 1; j < N_sz; j++) {
            swap(n[i], n[j]);
            ans = max(ans, solve(n, k - 1));
            swap(n[i], n[j]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    if (N < 10 || (N < 100 && N % 10 == 0)) {
        cout << "-1\n";
        return 0;
    }
    if (N == 1000000) {
        cout << N << "\n";
        return 0;
    }
    string N_str = to_string(N);
    N_sz = N_str.size();
    int sz = 1;
    for (int i = 0; i < N_sz; i++) {
        sz *= 10;
    }
    cache.resize(sz + 1, vector<int>(K));
    cout << solve(N_str, K) << "\n";
    return 0;
}
