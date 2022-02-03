#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string P;
int P_sz;
vector<vector<int>> cache(100, vector<int>(100));

bool check(string& s, int sz, int idx, int p_idx) {
    if (p_idx >= P_sz) {
        return idx >= sz;
    }
    if (idx >= sz) {
        while (p_idx < P_sz && P[p_idx] == '*') {
            p_idx++;
        }
        return p_idx >= P_sz;
    }
    int& ans = cache[idx][p_idx];
    if (ans >= 0) {
        return ans == 1;
    }
    while (p_idx < P_sz && P[p_idx] != '*') {
        if (s[idx] != P[p_idx]) {
            ans = 0;
            return false;
        }
        idx++;
        p_idx++;
    }
    if (p_idx >= P_sz) {
        ans = idx >= sz;
        return idx >= sz;
    }
    while (p_idx < P_sz && P[p_idx] == '*') {
        p_idx++;
    }
    if (p_idx >= P_sz) {
        ans = 1;
        return true;
    }
    for (int i = idx; i < sz; i++) {
        if (s[i] == P[p_idx]) {
            if (check(s, sz, i + 1, p_idx + 1)) {
                ans = 1;
                return true;
            }
        }
    }
    ans = 0;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> P;
    P_sz = P.size();
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string filename;
        cin >> filename;
        for (auto& row : cache) {
            fill(row.begin(), row.end(), -1);
        }
        if (check(filename, filename.size(), 0, 0)) {
            cout << filename << "\n";
        }
    }
    return 0;
}
