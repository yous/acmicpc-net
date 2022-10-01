#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = int(1e9) + 1;
int N, K;

int solve(int idx, vector<int>& requests, vector<int>& cache) {
    if (idx + K - 1 >= N) {
        return 0;
    }
    int& ans = cache[idx];
    if (ans < INF) {
        return ans;
    }
    int min_cost = requests[idx + K - 1];
    ans = min(ans, max(min_cost, solve(idx + K, requests, cache)));
    for (int i = idx + K - 2; i >= idx; i--) {
        if (requests[i] < min_cost) {
            min_cost = requests[i];
            ans = min(ans, max(min_cost, solve(i + 1, requests, cache)));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    vector<int> requests(N);
    for (auto& num : requests) {
        cin >> num;
    }
    vector<int> cache(N, INF);
    cout << solve(0, requests, cache) << "\n";
    return 0;
}
