#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int L, A;
    while (cin >> L >> A) {
        vector<pair<int, bool>> ants(A);
        int max_dist = -1;
        for (int i = 0; i < A; i++) {
            int x;
            char dir;
            cin >> x >> dir;
            ants[i] = {x, dir == 'L'};
            int dist = ants[i].second ? x : (L - x);
            if (max_dist < dist) {
                max_dist = dist;
            }
        }
        sort(ants.begin(), ants.end());
        cout << "The last ant will fall down in " << max_dist << " seconds - started at ";
        vector<int> fall(A);
        int idx = 0;
        while (idx < A && ants[idx].second) {
            fall[idx] = ants[idx].first;
            idx++;
        }
        if (idx < A) {
            queue<int> rights;
            vector<int> vals;
            int val = ants[idx].first;
            for (int i = idx + 1; i < A; i++) {
                if (!ants[i].second) {
                    rights.emplace(i);
                    vals.emplace_back(ants[i].first);
                } else {
                    if (rights.empty()) {
                        fall[idx] = ants[i].first;
                        idx = i;
                    } else {
                        fall[idx] = ants[i].first;
                        idx = rights.front();
                        rights.pop();
                        rights.emplace(i);
                    }
                }
            }
            fall[idx] = L - val;
            int val_idx = 0;
            while (!rights.empty()) {
                int i = rights.front();
                rights.pop();
                fall[i] = L - vals[val_idx];
                val_idx++;
            }
        }
        bool first = true;
        for (int i = 0; i < A; i++) {
            if (fall[i] == max_dist) {
                if (first) {
                    first = false;
                    cout << ants[i].first;
                } else {
                    cout << " and " << ants[i].first;
                }
            }
        }
        cout << ".\n";
    }
    return 0;
}
