#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> count(M);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int P;
            cin >> P;
            P--;
            if (j == 0) {
                count[P]++;
            } else if (j == num - 1) {
                count[P]++;
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i < M; i++) {
        sum += 1LL * count[i] * i;
    }
    long long ans_sum = sum;
    int ans = 0;
    int left_count = 0;
    int right_count = N * 2 - count[0];
    for (int st = 1; st < M; st++) {
        sum -= right_count;
        sum += left_count + count[st - 1];
        left_count += count[st - 1];
        right_count -= count[st];
        if (sum < ans_sum) {
            ans_sum = sum;
            ans = st;
        }
    }
    cout << ans + 1 << "\n";
    return 0;
}
