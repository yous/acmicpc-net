#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<vector<short>> ADJ;
vector<short> order;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    ADJ.resize(N);
    order.resize(N);
    for (int i = 0; i < M; i++) {
        short a, b;
        cin >> a >> b;
        ADJ[a - 1].push_back(b - 1);
        order[b - 1]++;
    }
    queue<short> qu;
    for (int i = 0; i < N; i++) {
        if (order[i] == 0) {
            qu.emplace(i);
        }
    }
    bool is_first = true;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (auto v : ADJ[u]) {
            order[v]--;
            if (order[v] == 0) {
                qu.emplace(v);
            }
        }
        if (is_first) {
            is_first = false;
            cout << u + 1;
        } else {
            cout << " " << u + 1;
        }
    }
    cout << "\n";
    return 0;
}
