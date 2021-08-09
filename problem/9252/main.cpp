#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S1, S2;
int sz1, sz2;
vector<vector<short>> cache;
vector<vector<char>> next_idx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S1 >> S2;
    sz1 = S1.size();
    sz2 = S2.size();
    cache.resize(sz1, vector<short>(sz2));
    next_idx.resize(sz1, vector<char>(sz2));
    for (int i = sz1 + sz2 - 2; i >= 0; i--) {
        for (int idx1 = min(sz1 - 1, i); idx1 >= max(0, i - sz2 + 1); idx1--) {
            int idx2 = i - idx1;
            if (S1[idx1] == S2[idx2]) {
                cache[idx1][idx2] = 1;
                if (idx1 < sz1 - 1 && idx2 < sz2 - 1) {
                    cache[idx1][idx2] += cache[idx1 + 1][idx2 + 1];
                }
                next_idx[idx1][idx2] = 3;
            } else {
                short nxt1 = 0;
                if (idx1 < sz1 - 1) {
                    nxt1 = cache[idx1 + 1][idx2];
                }
                short nxt2 = 0;
                if (idx2 < sz2 - 1) {
                    nxt2 = cache[idx1][idx2 + 1];
                }
                if (nxt1 >= nxt2) {
                    cache[idx1][idx2] = nxt1;
                    next_idx[idx1][idx2] = 1;
                } else {
                    cache[idx1][idx2] = nxt2;
                    next_idx[idx1][idx2] = 2;
                }
            }
        }
    }
    short len = cache[0][0];
    cout << len << "\n";
    if (len > 0) {
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < sz1 && idx2 < sz2) {
            switch (next_idx[idx1][idx2]) {
                case 1:
                    idx1++;
                    break;
                case 2:
                    idx2++;
                    break;
                case 3:
                    cout << S1[idx1];
                    idx1++;
                    idx2++;
                    break;
            }
        }
        cout << "\n";
    }
    return 0;
}
