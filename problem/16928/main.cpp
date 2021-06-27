#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short INF = 30000;
int N, M;
short portal[101];
short dist[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        portal[x] = y;
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        portal[x] = y;
    }
    fill(dist, dist + 101, INF);
    queue<int> qu;
    qu.push(1);
    short step = 0;
    bool found = false;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            int cur = qu.front();
            qu.pop();
            for (int i = 1; i <= 6; i++) {
                int ncur = cur + i;
                if (portal[ncur] > 0) {
                    ncur = portal[ncur];
                }
                if (ncur == 100) {
                    found = true;
                    cout << step + 1 << "\n";
                    break;
                }
                if (step + 1 < dist[ncur]) {
                    dist[ncur] = step + 1;
                    qu.push(ncur);
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
        step++;
    }
    return 0;
}
