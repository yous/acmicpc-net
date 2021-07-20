#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, K;
int cache[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    fill(cache, cache + 100001, INF);
    queue<int> qu;
    cache[N] = 0;
    qu.push(N);
    int sec = 0;
    int found = 0;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            int cur = qu.front();
            qu.pop();
            if (cur == K) {
                found++;
                continue;
            }
            if (cache[cur] < sec) {
                continue;
            }
            int nex = cur * 2;
            if (nex <= 100000) {
                if (sec + 1 <= cache[nex]) {
                    cache[nex] = sec + 1;
                    qu.push(nex);
                }
            }
            nex = cur + 1;
            if (nex <= 100000) {
                if (sec + 1 <= cache[nex]) {
                    cache[nex] = sec + 1;
                    qu.push(nex);
                }
            }
            nex = cur - 1;
            if (nex >= 0) {
                if (sec + 1 <= cache[nex]) {
                    cache[nex] = sec + 1;
                    qu.push(nex);
                }
            }
        }
        if (found > 0) {
            cout << sec << "\n" << found << "\n";
            break;
        }
        sec++;
    }
    return 0;
}
