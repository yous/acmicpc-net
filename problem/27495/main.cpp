#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<string>> mandalart(9, vector<string>(9));
    for (auto& row : mandalart) {
        for (auto& col : row) {
            cin >> col;
        }
    }
    vector<pair<string, int>> middles;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            middles.emplace_back(mandalart[i * 3 + 1][j * 3 + 1], i * 3 + j);
        }
    }
    sort(middles.begin(), middles.end());
    int middle_num = 1;
    for (auto& [middle, idx] : middles) {
        int x = idx % 3;
        int y = idx / 3;
        cout << "#" << middle_num << ". " << middle << "\n";
        vector<string> lowers;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                lowers.emplace_back(mandalart[y * 3 + i][x * 3 + j]);
            }
        }
        sort(lowers.begin(), lowers.end());
        int lower_num = 1;
        for (auto& lower : lowers) {
            cout << "#" << middle_num << "-" << lower_num << ". " << lower << "\n";
            lower_num++;
        }
        middle_num++;
    }
    return 0;
}
