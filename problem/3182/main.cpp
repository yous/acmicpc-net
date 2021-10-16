#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> ADJ;
vector<int> cache;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    ADJ.resize(N);
    cache.resize(N);
    for (int& num : ADJ) {
        cin >> num;
        num--;
    }
    int ans = 0;
    int max_cnt = 0;
    for (int i = 0; i < N; i++) {
        int u = i;
        int cnt = 1;
        vector<bool> visited(N);
        while (!visited[u] && cache[u] == 0) {
            visited[u] = true;
            u = ADJ[u];
            cnt++;
        }
        int end = u;
        if (cache[end] == 0) {
            int cycle_cnt = 0;
            do {
                u = ADJ[u];
                cycle_cnt++;
            } while (u != end);
            do {
                cache[u] = cycle_cnt;
                u = ADJ[u];
            } while (u != end);
        } else {
            cnt += cache[end];
        }
        u = i;
        int offset = 0;
        while (u != end) {
            cache[u] = cnt - offset;
            offset++;
            u = ADJ[u];
        }
        if (cnt > max_cnt) {
            ans = i + 1;
            max_cnt = cnt;
        }
    }
    cout << ans << "\n";
    return 0;
}
