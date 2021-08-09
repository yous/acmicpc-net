#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> liquid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    liquid.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
    }
    pair<int, int> ans;
    int min_d = 2e9;
    int lo = 0;
    int hi = N - 1;
    while (lo < hi) {
        int new_d = liquid[lo] + liquid[hi];
        if (new_d == 0) {
            cout << liquid[lo] << " " << liquid[hi] << "\n";
            return 0;
        }
        if (abs(new_d) < min_d) {
            ans = {liquid[lo], liquid[hi]};
            min_d = abs(new_d);
        }
        if (new_d < 0) {
            lo++;
        } else {
            hi--;
        }
    }
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
