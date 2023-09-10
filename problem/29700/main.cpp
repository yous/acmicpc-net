#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M, K;
    cin >> N >> M >> K;
    vector<vector<bool>> seats(N, vector<bool>(M));
    for (auto& row : seats) {
        for (int i = 0; i < M; i++) {
            char ch;
            cin >> ch;
            row[i] = ch == '1';
        }
    }
    int ans = 0;
    for (auto& row : seats) {
        int cur_streak = 0;
        for (int x = 0; x < K - 1; x++) {
            if (row[x]) {
                cur_streak = 0;
            } else {
                cur_streak++;
            }
        }
        for (int x = K - 1; x < M; x++) {
            if (cur_streak == K) {
                cur_streak--;
            }
            if (row[x]) {
                cur_streak = 0;
            } else {
                cur_streak++;
            }
            if (cur_streak == K) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
