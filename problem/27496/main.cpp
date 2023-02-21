#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    short L;
    cin >> N >> L;
    vector<short> alcohols(N);
    for (auto& num : alcohols) {
        cin >> num;
    }
    int ans = 0;
    int cur_alcohol = 0;
    for (int i = 0; i < L; i++) {
        cur_alcohol += alcohols[i];
        if (cur_alcohol >= 129 && cur_alcohol <= 138) {
            ans++;
        }
    }
    for (int i = L; i < N; i++) {
        cur_alcohol = cur_alcohol + alcohols[i] - alcohols[i - L];
        if (cur_alcohol >= 129 && cur_alcohol <= 138) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
