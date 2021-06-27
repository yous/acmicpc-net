#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int M, N;
vector<vector<short>> box;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;
    box.resize(N);
    int incomp_cnt = 0;
    queue<pair<int, int>> qu;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            short num;
            cin >> num;
            box[i].push_back(num);
            if (num == 1) {
                qu.emplace(i, j);
            } else if (num == 0) {
                incomp_cnt++;
            }
        }
    }
    if (incomp_cnt == 0) {
        cout << "0\n";
    } else {
        int step = 1;
        while (!qu.empty()) {
            int sz = qu.size();
            while (sz-- > 0) {
                auto& p = qu.front();
                int y = p.first,
                    x = p.second;
                qu.pop();
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || box[ny][nx] != 0) {
                        continue;
                    }
                    box[ny][nx] = 1;
                    incomp_cnt--;
                    if (incomp_cnt == 0) {
                        break;
                    }
                    qu.emplace(ny, nx);
                }
                if (incomp_cnt == 0) {
                    break;
                }
            }
            if (incomp_cnt == 0) {
                break;
            }
            step++;
        }
        if (incomp_cnt == 0) {
            cout << step << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
