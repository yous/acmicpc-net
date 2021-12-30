#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> sensors(N);
    for (int& num : sensors) {
        cin >> num;
    }
    sort(sensors.begin(), sensors.end());
    int ans = sensors[N - 1] - sensors[0];
    vector<int> diffs(N - 1);
    for (int i = 0; i < N - 1; i++) {
        diffs[i] = sensors[i + 1] - sensors[i];
    }
    sort(diffs.begin(), diffs.end());
    for (int i = 0; i < min(K - 1, N - 1); i++) {
        ans -= diffs[N - 2 - i];
    }
    cout << ans << "\n";
    return 0;
}
