#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<short> lectures(N);
    short max_len = 0;
    for (short& num : lectures) {
        cin >> num;
        max_len = max(max_len, num);
    }
    int lo = max_len;
    int hi = (N + M - 1) / M * 10000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cnt = 0;
        int idx = 0;
        int sum = 0;
        while (idx < N) {
            if (sum + lectures[idx] > mid) {
                cnt++;
                sum = 0;
            }
            sum += lectures[idx];
            idx++;
        }
        if (sum > 0) {
            cnt++;
        }
        if (cnt > M) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
    return 0;
}
