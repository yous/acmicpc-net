#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<string, string>> pairs(N);
    for (auto& [mentor, mentee] : pairs) {
        cin >> mentor >> mentee;
    }
    sort(pairs.begin(), pairs.end(), [](const auto& lhs, const auto& rhs) {
        if (lhs.first != rhs.first) {
            return lhs.first < rhs.first;
        }
        return lhs.second > rhs.second;
    });
    for (auto& [mentor, mentee] : pairs) {
        cout << mentor << " " << mentee << "\n";
    }
    return 0;
}
