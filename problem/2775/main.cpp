#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int num[15][15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i <= 14; i++) {
        num[0][i] = i;
    }
    for (int i = 1; i <= 14; i++) {
        int sum = 0;
        for (int j = 1; j <= 14; j++) {
            sum += num[i - 1][j];
            num[i][j] = sum;
        }
    }
    cin >> T;
    while (T-- > 0) {
        int k, n;
        cin >> k >> n;
        cout << num[k][n] << "\n";
    }
    return 0;
}
