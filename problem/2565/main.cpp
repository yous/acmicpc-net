#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> lines;
vector<int> cur_seq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        lines.emplace_back(a, b);
    }
    sort(lines.begin(), lines.end());
    for (int i = 0; i < N; i++) {
        int num = lines[i].second;
        if (cur_seq.empty() || cur_seq.back() < num) {
            cur_seq.push_back(num);
        } else {
            *lower_bound(cur_seq.begin(), cur_seq.end(), num) = num;
        }
    }
    cout << N - cur_seq.size() << "\n";
    return 0;
}
