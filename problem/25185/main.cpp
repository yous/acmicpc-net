#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        vector<string> cards(4);
        for (string& card : cards) {
            cin >> card;
        }
        sort(cards.begin(), cards.end());
        if ((cards[0] == cards[1] && cards[1] == cards[2]) ||
                (cards[1] == cards[2] && cards[2] == cards[3])) {
            cout << ":)\n";
            continue;
        }
        if (cards[0] == cards[1] && cards[2] == cards[3]) {
            cout << ":)\n";
            continue;
        }
        vector<vector<bool>> num_set(3, vector<bool>(9));
        auto char_to_idx = [](const char c) {
            if (c == 'm') {
                return 0;
            }
            if (c == 'p') {
                return 1;
            }
            return 2;
        };
        for (string& card : cards) {
            num_set[char_to_idx(card[1])][card[0] - '1'] = true;
        }
        bool found = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 2; j < 9; j++) {
                if (num_set[i][j - 2] && num_set[i][j - 1] && num_set[i][j]) {
                    found = true;
                    goto out;
                }
            }
        }
out:
        if (found) {
            cout << ":)\n";
        } else {
            cout << ":(\n";
        }
    }
    return 0;
}
