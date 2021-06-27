#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, K;
int dist[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    fill(dist, dist + 100001, INF);
    queue<int> qu;
    dist[N] = 0;
    qu.push(N);
    int step = 0;
    bool found = false;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            int x = qu.front();
            qu.pop();
            if (x == K) {
                found = true;
                break;
            }
            if (dist[x] < step) {
                continue;
            }
            if (x * 2 <= 100000) {
                if (step + 1 < dist[x * 2]) {
                    dist[x * 2] = step + 1;
                    qu.push(x * 2);
                }
            }
            if (x - 1 >= 0) {
                if (step + 1 < dist[x - 1]) {
                    dist[x - 1] = step + 1;
                    qu.push(x - 1);
                }
            }
            if (x + 1 <= 100000) {
                if (step + 1 < dist[x + 1]) {
                    dist[x + 1] = step + 1;
                    qu.push(x + 1);
                }
            }
        }
        if (found) {
            break;
        }
        step++;
    }
    cout << step << "\n";
    return 0;
}
