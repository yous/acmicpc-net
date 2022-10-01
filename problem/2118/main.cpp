#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> dist(N);
    int total = 0;
    for (auto& num : dist) {
        cin >> num;
        total += num;
    }
    int ans = 0;
    int sum = 0;
    int start_idx = 0;
    int end_idx = 0;
    while (start_idx < N) {
        while (sum <= total / 2) {
            ans = max(ans, sum);
            sum += dist[end_idx++];
            if (end_idx == N) {
                end_idx = 0;
            }
        }
        while (sum > total / 2) {
            ans = max(ans, min(sum, total - sum));
            sum -= dist[start_idx++];
            if (start_idx == N) {
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
