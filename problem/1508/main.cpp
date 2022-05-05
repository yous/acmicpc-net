#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    short M, K;
    cin >> N >> M >> K;
    vector<int> positions(K);
    for (int& num : positions) {
        cin >> num;
    }
    int lo = 1;
    int hi = N;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int prev_pos = positions[0];
        int idx = 1;
        int cnt = 1;
        while (idx < K) {
            if (positions[idx] - prev_pos >= mid) {
                cnt++;
                prev_pos = positions[idx];
            }
            idx++;
        }
        if (cnt >= M) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    int prev_pos = positions[0];
    int idx = 1;
    int cnt = 1;
    cout << "1";
    while (idx < K) {
        if (cnt < M && positions[idx] - prev_pos >= hi) {
            cnt++;
            prev_pos = positions[idx];
            cout << "1";
        } else {
            cout << "0";
        }
        idx++;
    }
    cout << "\n";
    return 0;
}
