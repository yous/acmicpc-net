#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> cache(5, vector<int>((1 << 15) + 1));
    cache[0][0] = 1;
    for (int i = 1; i * i <= (1 << 15); i++) {
        int i_sq = i * i;
        for (int cnt = 1; cnt <= 4; cnt++) {
            for (int j = 0; j + i_sq <= (1 << 15) + 1; j++) {
                cache[cnt][j + i_sq] += cache[cnt - 1][j];
            }
        }
    }
    int num;
    while (cin >> num) {
        if (num == 0) {
            break;
        }
        int ans = 0;
        for (int cnt = 1; cnt <= 4; cnt++) {
            ans += cache[cnt][num];
        }
        cout << ans << "\n";
    }
    return 0;
}
