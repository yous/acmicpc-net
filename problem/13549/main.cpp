#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, K;
vector<int> cache(100001, INF);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    queue<int> qu;
    int jump = N;
    while (jump <= 100000) {
        cache[jump] = 0;
        qu.push(jump);
        jump *= 2;
        if (jump == 0) {
            break;
        }
    }
    int step = 0;
    bool found = false;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            int cur = qu.front();
            qu.pop();
            if (cur == K) {
                found = true;
                break;
            }
            if (cache[cur] < step) {
                continue;
            }
            if (cur >= 1) {
                jump = cur - 1;
                while (jump <= 100000) {
                    if (step + 1 < cache[jump]) {
                        cache[jump] = step + 1;
                        qu.push(jump);
                    }
                    jump *= 2;
                    if (jump == 0) {
                        break;
                    }
                }
            }
            if (cur < 100000) {
                jump = cur + 1;
                while (jump <= 100000) {
                    if (step + 1 < cache[jump]) {
                        cache[jump] = step + 1;
                        qu.push(jump);
                    }
                    jump *= 2;
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
