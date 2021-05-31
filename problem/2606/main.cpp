#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<short> net[101];
bool virus[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    short p, q;
    while (M-- > 0) {
        cin >> p >> q;
        net[p].push_back(q);
        net[q].push_back(p);
    }
    queue<short> qu;
    qu.push(1);
    short ans = 0;
    while (!qu.empty()) {
        short front = qu.front();
        qu.pop();
        if (virus[front]) {
            continue;
        }
        virus[front] = true;
        ans++;
        for (short other : net[front]) {
            if (!virus[other]) {
                qu.push(other);
            }
        }
    }
    cout << ans - 1 << "\n";
    return 0;
}
