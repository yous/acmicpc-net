#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<int> grundy(N + 1);
    for (int n = 2; n <= N; n++) {
        vector<bool> actions(n + 1);
        for (int i = 0; i <= (n - 2) / 2; i++) {
            actions[grundy[i] ^ grundy[n - 2 - i]] = true;
        }
        grundy[n] = distance(actions.begin(), min_element(actions.begin(), actions.end()));
    }
    cout << (grundy[N] == 0 ? 2 : 1) << "\n";
    return 0;
}
