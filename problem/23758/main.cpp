#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> cnt(31);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cnt[31 - __builtin_clz(num)]++;
    }
    long long ans = 1;
    int num_cnt = 0;
    for (int i = 0; i < 31; i++) {
        if (num_cnt + cnt[i] >= (N + 1) / 2) {
            cout << ans + ((N + 1) / 2 - num_cnt) * i << "\n";
            break;
        }
        ans += cnt[i] * i;
        num_cnt += cnt[i];
    }
    return 0;
}
