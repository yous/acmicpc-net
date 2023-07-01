#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> prefix_sum(N);
    int sum = 0;
    for (int& num : prefix_sum) {
        cin >> num;
        sum += num;
        num = sum;
    }
    if (sum % 4 != 0) {
        cout << "0\n";
        return 0;
    }
    int target = sum / 4;
    long long cnt[3] = {0};
    for (int i = 0; i < N - 1; i++) {
        if (prefix_sum[i] == target * 3) {
            cnt[2] += cnt[1];
        }
        if (prefix_sum[i] == target * 2) {
            cnt[1] += cnt[0];
        }
        if (prefix_sum[i] == target) {
            cnt[0]++;
        }
    }
    cout << cnt[2] << "\n";
    return 0;
}
