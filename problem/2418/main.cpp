#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const short dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const short dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
short H, W, L;
string target;
vector<string> field;
vector<vector<vector<long long>>> cache;

long long solve(short y, short x, short l) {
    if (l == L) {
        return 1;
    }
    long long& ans = cache[y][x][l];
    if (ans >= 0) {
        return ans;
    }
    ans = 0;
    for (int i = 0; i < 8; i++) {
        short ny = y + dy[i];
        short nx = x + dx[i];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W || field[ny][nx] != target[l]) {
            continue;
        }
        ans += solve(ny, nx, l + 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> H >> W >> L;
    field.resize(H);
    for (string& row : field) {
        cin >> row;
    }
    cache.resize(H, vector<vector<long long>>(W, vector<long long>(L, -1)));
    cin >> target;
    long long ans = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (field[y][x] == target[0]) {
                ans += solve(y, x, 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
