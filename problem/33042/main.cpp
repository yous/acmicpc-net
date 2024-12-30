#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<vector<short>> counts(4, vector<short>(9));
    short ans = 0;
    for (int i = 0; i < N; i++) {
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
        counts[type][str[0] - '1']++;
        if (ans == 0 && counts[type][str[0] - '1'] == 5) {
            ans = i + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
