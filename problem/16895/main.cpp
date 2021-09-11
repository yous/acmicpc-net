#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> stones;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    stones.resize(N);
    int grundy = 0;
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
        grundy ^= stones[i];
    }
    if (grundy == 0) {
        cout << "0\n";
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (stones[i] > (grundy ^ stones[i])) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
