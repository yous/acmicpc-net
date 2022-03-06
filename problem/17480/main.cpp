#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

string S;
short total_cnt = 0;
set<string> combi;

void solve(string& s, int lo, int hi) {
    if (lo == hi) {
        combi.insert(s);
        return;
    }
    int mid = (lo + hi) / 2;
    reverse(s.begin() + lo, s.begin() + mid + 1);
    solve(s, mid + 1, hi);
    reverse(s.begin() + lo, s.begin() + mid + 1);
    reverse(s.begin() + mid + 1, s.begin() + hi + 1);
    solve(s, lo, mid);
    reverse(s.begin() + mid + 1, s.begin() + hi + 1);
    if ((hi - lo + 1) % 2 == 1) {
        reverse(s.begin() + lo, s.begin() + mid);
        solve(s, mid, hi);
        reverse(s.begin() + lo, s.begin() + mid);
        reverse(s.begin() + mid, s.begin() + hi + 1);
        solve(s, lo, mid - 1);
        reverse(s.begin() + mid, s.begin() + hi + 1);
    }
}

void gen(string s) {
    solve(s, 0, total_cnt - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    short alpha[26] = {0};
    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        cin >> alpha[ch - 'a'];
        total_cnt += alpha[ch - 'a'];
    }
    short cnt[26] = {0};
    cin >> S;
    int sz = S.size();
    for (int i = 0; i < total_cnt - 1; i++) {
        cnt[S[i] - 'a']++;
    }
    for (int i = total_cnt - 1; i < sz; i++) {
        cnt[S[i] - 'a']++;
        bool found = true;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] != alpha[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            gen(S.substr(i - total_cnt + 1, total_cnt));
        }
        cnt[S[i - total_cnt + 1] - 'a']--;
    }
    cout << combi.size() << "\n";
    return 0;
}
