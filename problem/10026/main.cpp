#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N;
char field[100][100];
vector<bool> visited[100];

void dfs(int y, int x, bool rg_same) {
    char color = field[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) {
            continue;
        }
        if (rg_same) {
            if ((color != 'B' && field[ny][nx] == 'B') || (color == 'B' && field[ny][nx] != 'B')) {
                continue;
            }
        } else {
            if (field[ny][nx] != color) {
                continue;
            }
        }
        visited[ny][nx] = true;
        dfs(ny, nx, rg_same);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> field[i][j];
        }
        visited[i].resize(N);
    }
    int r_g_b = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x]) {
                visited[y][x] = true;
                r_g_b++;
                dfs(y, x, false);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        visited[i].clear();
        visited[i].resize(N);
    }
    int rg_b = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!visited[y][x]) {
                visited[y][x] = true;
                rg_b++;
                dfs(y, x, true);
            }
        }
    }
    cout << r_g_b << " " << rg_b << "\n";
    return 0;
}
