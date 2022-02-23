#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        int K;
        cin >> K;
        priority_queue<long long> pq;
        for (int i = 0; i < K; i++) {
            short num;
            cin >> num;
            pq.emplace(-num);
        }
        long long ans = 0;
        while (!pq.empty()) {
            long long file1 = pq.top();
            file1 = -file1;
            pq.pop();
            if (pq.empty()) {
                break;
            }
            long long file2 = pq.top();
            file2 = -file2;
            pq.pop();
            ans += file1 + file2;
            pq.emplace(-(file1 + file2));
        }
        cout << ans << "\n";
    }
    return 0;
}
