#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int ans = 0;
    string key = "2023";
    for (int num = 2023; num <= N; num++) {
        string s = to_string(num);
        int idx = 0;
        for (auto ch : s) {
            if (ch == key[idx]) {
                idx++;
            }
            if (idx == 4) {
                break;
            }
        }
        if (idx == 4) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
