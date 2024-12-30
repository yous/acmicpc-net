#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<short, short>> hands(N);
    for (auto& hand : hands) {
        string str;
        cin >> str;
        int type;
        switch (str[1]) {
            case 'm':
                type = 0;
                break;
            case 'p':
                type = 1;
                break;
            case 's':
                type = 2;
                break;
            default:
                type = 3;
                break;
        }
        hand = {type, str[0] - '1'};
    }
    vector<vector<int>> counts(4, vector<int>(9));
    int ans = N + 1;
    int l_idx = 0;
    int r_idx = 0;
    while (r_idx < N) {
        auto& [type, num] = hands[r_idx];
        counts[type][num]++;
        if (counts[type][num] == 5) {
            while (l_idx <= r_idx) {
                auto& [p_type, p_num] = hands[l_idx];
                if (type == p_type && num == p_num) {
                    ans = min(ans, r_idx - l_idx + 1);
                    counts[p_type][p_num]--;
                    l_idx++;
                    break;
                }
                counts[p_type][p_num]--;
                l_idx++;
            }
        }
        r_idx++;
    }
    if (ans == N + 1) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
