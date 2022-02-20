#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> cache(182, vector<int>((1 << 15) + 1));
    for (int i = 1; i * i <= (1 << 15); i++) {
        int i_sq = i * i;
        cache[i][i_sq]++;
        for (int j = i; i_sq + j * j <= (1 << 15); j++) {
            int j_sq = j * j;
            cache[i][i_sq + j_sq]++;
            for (int k = j; i_sq + j_sq + k * k <= (1 << 15); k++) {
                int k_sq = k * k;
                cache[i][i_sq + j_sq + k_sq]++;
            }
        }
    }
    int num;
    while (cin >> num) {
        if (num == 0) {
            break;
        }
        int ans = 0;
        for (int i = 1; i * i <= num; i++) {
            int rem = num - i * i;
            if (rem == 0) {
                ans++;
            } else {
                for (int j = i; j * j <= rem; j++) {
                    ans += cache[j][num - i * i];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
