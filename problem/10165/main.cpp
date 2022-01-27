#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> buses;
    vector<bool> covered(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            buses.emplace_back(a, -b, i);
            if (a > 0) {
                buses.emplace_back(-(N - a), N - b, i);
            }
        } else {
            buses.emplace_back(-(N - a), -b, i);
        }
    }
    sort(buses.begin(), buses.end());
    int max_end = -N;
    for (auto [a, b, m] : buses) {
        b = -b;
        if (b <= max_end) {
            if (!covered[m]) {
                covered[m] = true;
            }
        } else {
            max_end = b;
        }
    }
    bool first = true;
    for (int i = 0; i < M; i++) {
        if (!covered[i]) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << i + 1;
        }
    }
    cout << "\n";
    return 0;
}
