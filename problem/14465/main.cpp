#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, B, K;
vector<int> broken;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K >> B;
    broken.resize(B);
    for (int& num : broken) {
        cin >> num;
    }
    sort(broken.begin(), broken.end());
    int fix_cnt = 0;
    auto it = broken.begin();
    for (int i = 1; i <= K; i++) {
        if (it != broken.end() && *it == i) {
            fix_cnt++;
            it++;
        }
    }
    int ans = fix_cnt;
    auto lo = broken.begin();
    for (int i = K + 1; i <= N; i++) {
        if (lo != broken.end() && *lo == i - K) {
            fix_cnt--;
            lo++;
        }
        if (it != broken.end() && *it == i) {
            fix_cnt++;
            it++;
        }
        ans = min(ans, fix_cnt);
    }
    cout << ans << "\n";
    return 0;
}
