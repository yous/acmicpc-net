#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int dz[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, 0, -1, 1};
int M, N, H;
vector<vector<vector<short>>> box;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N >> H;
    box.resize(H);
    queue<tuple<int, int, int>> qu;
    int incomp_cnt = 0;
    for (int i = 0; i < H; i++) {
        box[i].resize(N);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                short num;
                cin >> num;
                box[i][j].push_back(num);
                if (num == 1) {
                    qu.emplace(i, j, k);
                } else if (num == 0) {
                    incomp_cnt++;
                }
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
                int z, y, x;
                tie(z, y, x) = qu.front();
                qu.pop();
                for (int i = 0; i < 6; i++) {
                    int nz = z + dz[i];
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M || box[nz][ny][nx] != 0) {
                        continue;
                    }
                    box[nz][ny][nx] = 1;
                    incomp_cnt--;
                    if (incomp_cnt == 0) {
                        break;
                    }
                    qu.emplace(nz, ny, nx);
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
