#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
long long board[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    int i, j;
    char ch;
    for (i = 0; i < N; i++) {
        long long num = 0;
        for (j = 0; j < M; j++) {
            cin >> ch;
            num = num * 2 + (ch == 'B');
        }
        board[i] = num;
    }
    int ans = N * M;
    int cur_b;
    for (j = 0; j < M - 7; j++) {
        cur_b = 0;
        for (i = 0; i < 8; i++) {
            int bits = (board[i] >> (M - 8 - j)) & 0b11111111;
            int compare = 0b10101010;
            if (i % 2) {
                compare ^= 0b11111111;
            }
            cur_b += __builtin_popcount(bits ^ compare);
        }
        ans = min({ans, cur_b, 64 - cur_b});
        for (i = 8; i < N; i++) {
            int bits = (board[i - 8] >> (M - 8 - j)) & 0b11111111;
            int compare = 0b10101010;
            if (i % 2) {
                compare ^= 0b11111111;
            }
            cur_b -= __builtin_popcount(bits ^ compare);
            bits = (board[i] >> (M - 8 - j)) & 0b11111111;
            cur_b += __builtin_popcount(bits ^ compare);
            ans = min({ans, cur_b, 64 - cur_b});
        }
    }
    cout << ans << "\n";
    return 0;
}
