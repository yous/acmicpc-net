#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> minmax(7, {N + 1, -1});
    long long sum = 0;
    minmax[0] = {0, 0};
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        sum += num;
        int rem = sum % 7;
        if (minmax[rem].first > i) {
            minmax[rem].first = i;
        }
        if (minmax[rem].second < i) {
            minmax[rem].second = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        int res = minmax[i].second - minmax[i].first;
        ans = max(ans, res);
    }
    cout << ans << "\n";
    return 0;
}
