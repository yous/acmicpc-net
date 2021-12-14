#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

int N, M;
set<int> smalls;
bool visited[10001][150];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        smalls.insert(num);
    }
    queue<pair<int, int>> bfs;
    bfs.push({1, 0});
    int step = 0;
    bool found = false;
    while (!bfs.empty()) {
        int sz = bfs.size();
        while (sz-- > 0) {
            int stone, velo;
            tie(stone, velo) = bfs.front();
            bfs.pop();
            if (stone == N) {
                found = true;
                cout << step << "\n";
                break;
            }
            for (int dv = -1; dv <= 1; dv++) {
                int new_velo = velo + dv;
                int new_stone = stone + new_velo;
                if (new_stone > N || new_velo < 1 || smalls.find(new_stone) != smalls.end() || visited[new_stone][new_velo]) {
                    continue;
                }
                bfs.push({new_stone, new_velo});
                visited[new_stone][new_velo] = true;
            }
        }
        if (found) {
            break;
        }
        step++;
    }
    if (!found) {
        cout << "-1\n";
    }
    return 0;
}
