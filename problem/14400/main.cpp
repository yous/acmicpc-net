#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> xs(N);
    vector<int> ys(N);
    for (int i = 0; i < N; i++) {
        cin >> xs[i] >> ys[i];
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int mid_x = xs[N / 2];
    int mid_y = ys[N / 2];
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(mid_x - xs[i]);
        ans += abs(mid_y - ys[i]);
    }
    cout << ans << "\n";
    return 0;
}
