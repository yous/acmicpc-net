#include <algorithm>
#include <iostream>
#include <stack>
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
    stack<char> ans;
    for (int i = 0; i < S_sz; i++) {
        if (i >= pat_sz - 1 && S[i] == pat[pat_sz - 1]) {
            int search = pat_sz - 2;
            while (!ans.empty() && search >= 0 && ans.top() == pat[search]) {
                ans.pop();
                search--;
            }
            if (search == -1) {
                continue;
            }
            search++;
            while (search < pat_sz - 1) {
                ans.push(pat[search]);
                search++;
            }
            ans.push(S[i]);
        } else {
            ans.push(S[i]);
        }
    }
    if (ans.empty()) {
        cout << "FRULA\n";
    } else {
        stack<char> st;
        while (!ans.empty()) {
            st.push(ans.top());
            ans.pop();
        }
        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << "\n";
    }
    return 0;
}
