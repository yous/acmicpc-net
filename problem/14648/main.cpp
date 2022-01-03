#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<long long> prefix_sum(N + 1);
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        sum += num;
        prefix_sum[i] = sum;
    }
    for (int i = 0; i < Q; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            cout << prefix_sum[b] - prefix_sum[a - 1] << "\n";
            long long diff = (prefix_sum[b] - prefix_sum[b - 1]) - (prefix_sum[a] - prefix_sum[a - 1]);
            for (int j = a; j < b; j++) {
                prefix_sum[j] += diff;
            }
        } else {
            int c, d;
            cin >> c >> d;
            cout << (prefix_sum[b] - prefix_sum[a - 1]) - (prefix_sum[d] - prefix_sum[c - 1]) << "\n";
        }
    }
    return 0;
}
