#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const char* mbti[] = {"NS", "FT", "PJ"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<string> board(N);
    for (string& row : board) {
        cin >> row;
    }
    int ans = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] != 'E' && board[y][x] != 'I') {
                continue;
            }
            for (int i = 0; i < 8; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
                    continue;
                }
                int pos = 0;
                while (pos < 3 && ny >= 0 && ny < N && nx >= 0 && nx < M && (board[ny][nx] == mbti[pos][0] || board[ny][nx] == mbti[pos][1])) {
                    pos++;
                    ny += dy[i];
                    nx += dx[i];
                }
                if (pos == 3) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
