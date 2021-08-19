#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M;
vector<int> mem;
vector<int> cost;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        mem.push_back(num);
    }
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cost.push_back(num);
    }
    vector<int> cur_remain(10001, INF);
    vector<int> next_remain(10001, INF);
    cur_remain[0] = M;
    int ans = 10000;
    for (int i = 0; i < N; i++) {
        for (int c = 10000; c >= 0; c--) {
            int remain = cur_remain[c];
            if (remain <= 0) {
                continue;
            }
            if (remain < INF) {
                next_remain[c] = min(next_remain[c], remain);
                int next_c = c + cost[i];
                int next_m = remain - mem[i];
                next_remain[next_c] = min(next_remain[next_c], next_m);
                if (next_m <= 0 && ans > next_c) {
                    ans = next_c;
                }
            }
        }
        swap(cur_remain, next_remain);
    }
    cout << ans << "\n";
    return 0;
}
