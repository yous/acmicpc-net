#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S;

vector<int> make_z(const string& str) {
    int sz = str.size();
    vector<int> z(sz);
    int l = 0;
    int r = 0;
    for (int i = 1; i < sz; i++) {
        if (i > r) {
            l = r = i;
            while (r < sz && str[r - l] == str[r]) {
                r++;
            }
            z[i] = r - l;
            r--;
        } else {
            int pre_i = i - l;
            if (z[pre_i] < r - i + 1) {
                z[i] = z[pre_i];
            } else {
                l = i;
                while (r < sz && str[r - l] == str[r]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    int sz = S.size();
    auto z = make_z(S);
    int ans = 0;
    int prev_max_z = 0;
    for (int i = sz - 1; i >= 0; i--) {
        if (i + z[i] == sz) {
            ans = prev_max_z;
            prev_max_z = z[i];
        } else if (z[i] >= prev_max_z) {
            ans = prev_max_z;
        }
    }
    if (ans > 0) {
        for (int i = 0; i < ans; i++) {
            cout << S[i];
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
