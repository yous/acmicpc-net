#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N;
vector<string> field;

int bfs(int y, int x) {
    queue<pair<int, int>> qu;
    field[y][x] = '0';
    int cnt = 1;
    qu.emplace(y, x);
    while (!qu.empty()) {
        auto& p = qu.front();
        int y = p.first,
            x = p.second;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N || field[ny][nx] == '0') {
                continue;
            }
            field[ny][nx] = '0';
            cnt++;
            qu.emplace(ny, nx);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        field.push_back(row);
    }
    vector<int> house_nums;
    int group_cnt = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (field[y][x] == '1') {
                group_cnt++;
                house_nums.push_back(bfs(y, x));
            }
        }
    }
    cout << group_cnt << "\n";
    sort(house_nums.begin(), house_nums.end());
    for (auto num : house_nums) {
        cout << num << "\n";
    }
    return 0;
}
