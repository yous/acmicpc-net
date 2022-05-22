#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short time;
    vector<short> wrong_cnt(26);
    int cnt = 0;
    int ans = 0;
    while (cin >> time) {
        if (time == -1) {
            break;
        }
        char prob;
        cin >> prob;
        string result;
        cin >> result;
        if (result[0] == 'r') {
            cnt++;
            ans += time + wrong_cnt[prob - 'A'] * 20;
        } else {
            wrong_cnt[prob - 'A']++;
        }
    }
    cout << cnt << " " << ans << "\n";
    return 0;
}
