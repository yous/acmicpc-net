#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, N;
    cin >> T >> N;
    vector<short> locations(N);
    vector<vector<int>> items(N, vector<int>(53));
    vector<int> cheats;
    int blocked_cnt = 0;
    vector<bool> blocked(N);
    for (int t = 1; t <= T; t++) {
        int num, player;
        char act;
        int arg1, arg2;
        cin >> num >> player >> act >> arg1;
        player--;
        arg1--;
        switch (act) {
            case 'M':
                locations[player] = arg1;
                break;
            case 'F':
                if (locations[player] != arg1) {
                    cheats.emplace_back(t);
                }
                items[player][arg1]++;
                break;
            case 'C':
                cin >> arg2;
                arg2--;
                if (items[player][arg1] == 0 || items[player][arg2] == 0) {
                    cheats.emplace_back(t);
                }
                if (items[player][arg1] > 0) {
                    items[player][arg1]--;
                }
                if (items[player][arg2] > 0) {
                    items[player][arg2]--;
                }
                break;
            case 'A':
                if (locations[player] != locations[arg1]) {
                    cheats.emplace_back(t);
                    if (!blocked[player]) {
                        blocked_cnt++;
                        blocked[player] = true;
                    }
                }
                break;
        }
    }
    cout << cheats.size() << "\n";
    if (!cheats.empty()) {
        cout << cheats[0];
        for (int i = 1; i < cheats.size(); i++) {
            cout << " " << cheats[i];
        }
        cout << "\n";
    }
    cout << blocked_cnt << "\n";
    if (blocked_cnt > 0) {
        bool first = true;
        for (int i = 0; i < N; i++) {
            if (blocked[i]) {
                if (first) {
                    first = false;
                } else {
                    cout << " ";
                }
                cout << i + 1;
            }
        }
        cout << "\n";
    }
    return 0;
}
