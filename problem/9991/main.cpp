#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int W, N;
vector<pair<string, int>> dict;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> W >> N;
    for (int i = 0; i < W; i++) {
        string word;
        cin >> word;
        dict.emplace_back(word, i + 1);
    }
    sort(dict.begin(), dict.end());
    for (int i = 0; i < N; i++) {
        int idx;
        string part;
        cin >> idx >> part;
        int first_idx = lower_bound(dict.begin(), dict.end(), make_pair(part, 0)) - dict.begin();
        if (first_idx + idx - 1 < W && dict[first_idx + idx - 1].first.rfind(part, 0) == 0) {
            cout << dict[first_idx + idx - 1].second << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}
