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
    cache.resize(sz1 + 1, vector<short>(sz2 + 1));
    next_idx.resize(sz1, vector<char>(sz2));
    for (int i = sz1; i >= 0; i--) {
        for (int j = sz2; j >= 0; j--) {
            if (i == sz1 || j == sz2) {
                cache[i][j] = 0;
            } else if (S1[i] == S2[j]) {
                cache[i][j] = 1 + cache[i + 1][j + 1];
                next_idx[i][j] = 3;
            } else {
                short nxt1 = cache[i + 1][j];
                short nxt2 = cache[i][j + 1];
                if (nxt1 >= nxt2) {
                    cache[i][j] = nxt1;
                    next_idx[i][j] = 1;
                } else {
                    cache[i][j] = nxt2;
                    next_idx[i][j] = 2;
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
