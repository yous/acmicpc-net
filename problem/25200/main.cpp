#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> transitions(M);
    for (auto& [u, v] : transitions) {
        cin >> u >> v;
    }
    vector<int> group(N);
    for (int i = 0; i < N; i++) {
        group[i] = i + 1;
    }
    for (int i = M - 1; i >= 0; i--) {
        auto [u, v] = transitions[i];
        group[u - 1] = group[v - 1];
    }
    cout << group[0];
    for (int i = 1; i < N; i++) {
        cout << " " << group[i];
    }
    cout << "\n";
    return 0;
}
