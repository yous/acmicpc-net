#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S1, S2;
int sz1, sz2;
vector<vector<short>> cache;
vector<vector<char>> next_idx;

short solve(int idx1, int idx2) {
    if (idx1 == sz1 || idx2 == sz2) {
        return 0;
    }
    short& ans = cache[idx1][idx2];
    char& nxt = next_idx[idx1][idx2];
    if (ans >= 0) {
        return ans;
    }
    if (S1[idx1] == S2[idx2]) {
        ans = 1 + solve(idx1 + 1, idx2 + 1);
        nxt = 3;
    } else {
        int nxt1 = solve(idx1 + 1, idx2);
        int nxt2 = solve(idx1, idx2 + 1);
        if (nxt1 >= nxt2) {
            ans = nxt1;
            nxt = 1;
        } else {
            ans = nxt2;
            nxt = 2;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S1 >> S2;
    sz1 = S1.size();
    sz2 = S2.size();
    cache.resize(sz1, vector<short>(sz2, -1));
    next_idx.resize(sz1, vector<char>(sz2));
    int len = solve(0, 0);
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
