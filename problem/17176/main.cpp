#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> count(53);
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        count[num]++;
    }
    cin.ignore(1);
    string S;
    getline(cin, S);
    for (auto& ch : S) {
        int idx;
        if (ch == ' ') {
            idx = 0;
        } else if (ch <= 'Z') {
            idx = ch - 'A' + 1;
        } else if (ch <= 'z') {
            idx = ch - 'a' + 27;
        } else {
            continue;
        }
        if (count[idx] == 0) {
            cout << "n\n";
            return 0;
        }
        count[idx]--;
    }
    for (int i = 0; i <= 52; i++) {
        if (count[i] > 0) {
            cout << "n\n";
            return 0;
        }
    }
    cout << "y\n";
    return 0;
}
