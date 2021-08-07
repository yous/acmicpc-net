#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

string S;
string pat;
int S_sz;
int pat_sz;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S >> pat;
    S_sz = S.size();
    pat_sz = pat.size();
    deque<char> ans;
    for (int i = 0; i < S_sz; i++) {
        if (i >= pat_sz - 1 && S[i] == pat[pat_sz - 1]) {
            int search = pat_sz - 2;
            while (!ans.empty() && search >= 0 && ans.back() == pat[search]) {
                ans.pop_back();
                search--;
            }
            if (search == -1) {
                continue;
            }
            search++;
            while (search < pat_sz - 1) {
                ans.push_back(pat[search]);
                search++;
            }
            ans.push_back(S[i]);
        } else {
            ans.push_back(S[i]);
        }
    }
    if (ans.empty()) {
        cout << "FRULA\n";
    } else {
        while (!ans.empty()) {
            cout << ans.front();
            ans.pop_front();
        }
        cout << "\n";
    }
    return 0;
}
