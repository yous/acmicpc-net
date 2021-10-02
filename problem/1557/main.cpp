#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> mobius(44723);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    mobius[1] = 1;
    for (int i = 1; i <= 44722; i++) {
        if (mobius[i] == 0) {
            continue;
        }
        for (int j = i * 2; j <= 44722; j += i) {
            mobius[j] -= mobius[i];
        }
    }
    int lo = K;
    int hi = K * 2;
    while (lo <= hi) {
        int mid = (0LL + lo + hi) / 2;
        int cnt = 0;
        for (int i = 1; i * i <= mid; i++) {
            int num = mid / (i * i);
            cnt += num * mobius[i];
        }
        if (cnt >= K) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
    return 0;
}
