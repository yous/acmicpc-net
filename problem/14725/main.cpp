#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N;
int cur_idx = 1;
vector<map<string, int>> maps(1);

void dfs(int idx, int depth) {
    for (auto [word, next_idx] : maps[idx]) {
        for (int i = 0; i < depth; i++) {
            cout << "--";
        }
        cout << word << "\n";
        dfs(next_idx, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        int idx = 0;
        for (int j = 0; j < K; j++) {
            string word;
            cin >> word;
            auto it = maps[idx].find(word);
            if (it == maps[idx].end()) {
                maps.emplace_back(map<string, int>());
                maps[idx].emplace(word, cur_idx);
                idx = cur_idx;
                cur_idx++;
            } else {
                idx = it->second;
            }
        }
    }
    dfs(0, 0);
    return 0;
}
