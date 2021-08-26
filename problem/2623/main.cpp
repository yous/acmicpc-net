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
        int cnt;
        cin >> cnt;
        if (cnt == 0) {
            continue;
        }
        int num;
        cin >> num;
        int prev = num - 1;
        for (int j = 1; j < cnt; j++) {
            int num;
            cin >> num;
            ADJ[prev].push_back(num - 1);
            order[num - 1]++;
            prev = num - 1;
        }
    }
    queue<short> qu;
    for (int i = 0; i < N; i++) {
        if (order[i] == 0) {
            qu.emplace(i);
        }
    }
    vector<short> ans;
    while (!qu.empty()) {
        short u = qu.front();
        qu.pop();
        ans.emplace_back(u + 1);
        for (auto v : ADJ[u]) {
            order[v]--;
            if (order[v] == 0) {
                qu.emplace(v);
            }
        }
    }
    if (ans.size() != N) {
        cout << "0\n";
    } else {
        for (int i = 0; i < N; i++) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}
