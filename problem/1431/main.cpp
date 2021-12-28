#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<string, int>> guitars(N);
    for (auto& [serial, num] : guitars) {
        cin >> serial;
        num = 0;
        for (char ch : serial) {
            if (ch >= '0' && ch <= '9') {
                num += ch - '0';
            }
        }
    }
    sort(guitars.begin(), guitars.end(), [&](const pair<string, int>& lhs, const pair<string, int>& rhs) {
        if (lhs.first.size() != rhs.first.size()) {
            return lhs.first.size() < rhs.first.size();
        }
        if (lhs.second != rhs.second) {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
    });
    for (auto& [serial, num] : guitars) {
        cout << serial << "\n";
    }
    return 0;
}
