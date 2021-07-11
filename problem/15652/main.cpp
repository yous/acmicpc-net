#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

void solve(int idx, vector<int>& selected) {
    int sz = selected.size();
    if (sz == M) {
        cout << selected[0];
        for (int i = 1; i < M; i++) {
            cout << " " << selected[i];
        }
        cout << "\n";
        return;
    }
    if (idx == N) {
        return;
    }
    selected.push_back(idx + 1);
    solve(idx, selected);
    selected.pop_back();
    solve(idx + 1, selected);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    vector<int> selected;
    solve(0, selected);
    return 0;
}
