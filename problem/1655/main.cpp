#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> cnt(20001);
    int sqrt_sz = sqrt(20001);
    vector<int> chunks(sqrt_sz);
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        num += 10000;
        cnt[num]++;
        chunks[num / sqrt_sz]++;
        int mid = i / 2 + 1;
        int cur_cnt = 0;
        int idx = 0;
        while (idx < sqrt_sz && cur_cnt + chunks[idx] < mid) {
            cur_cnt += chunks[idx];
            idx++;
        }
        idx *= sqrt_sz;
        while (cur_cnt + cnt[idx] < mid) {
            cur_cnt += cnt[idx];
            idx++;
        }
        cout << idx - 10000 << "\n";
    }
    return 0;
}
