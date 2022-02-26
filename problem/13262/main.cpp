#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, K;
vector<int> A;
vector<long long> prev_cache;
vector<long long> cur_cache;

void solve(int l, int r, int optl, int optr) {
    if (l > r) {
        return;
    }
    int mid = (l + r) / 2;
    pair<long long, int> opt = {0, -1};
    int cost = 0;
    for (int i = mid; i > optr; i--) {
        cost |= A[i];
    }
    for (int i = min(optr, mid), st = optl; i >= st; i--) {
        cost |= A[i];
        opt = max(opt, {(i > 0 ? prev_cache[i - 1] : 0) + cost, i});
    }
    cur_cache[mid] = opt.first;
    solve(l, mid - 1, optl, opt.second);
    solve(mid + 1, r, opt.second, optr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    A.resize(N);
    for (int& num : A) {
        cin >> num;
    }
    prev_cache.resize(N);
    cur_cache.resize(N);
    int cost = 0;
    for (int i = 0; i < N; i++) {
        cost |= A[i];
        prev_cache[i] = cost;
    }
    for (int i = 1; i < K; i++) {
        solve(0, N - 1, 0, N - 1);
        swap(prev_cache, cur_cache);
    }
    cout << prev_cache[N - 1] << "\n";
    return 0;
}
