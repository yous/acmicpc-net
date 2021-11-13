#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S, P;
int S_sz, P_sz;
vector<int> pi;

void make_pi(const string& str) {
    int sz = str.size();
    int pos = 1;
    int matched = 0;
    while (pos + matched < sz) {
        if (str[pos + matched] == str[matched]) {
            matched++;
            pi[pos + matched - 1] = matched;
        } else if (matched == 0) {
            pos++;
        } else {
            pos += matched - pi[matched - 1];
            matched = pi[matched - 1];
        }
    }
}

bool match(const string& line, const string& word) {
    int line_sz = line.size();
    int word_sz = word.size();
    int pos = 0;
    int matched = 0;
    while (pos + word_sz <= line_sz) {
        if (matched < word_sz && line[pos + matched] == word[matched]) {
            matched++;
            if (matched == word_sz) {
                return true;
            }
        } else if (matched == 0) {
            pos++;
        } else {
            pos += matched - pi[matched - 1];
            matched = pi[matched - 1];
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S >> P;
    S_sz = S.size();
    P_sz = P.size();
    pi.resize(P_sz);
    make_pi(P);
    cout << (match(S, P) ? 1 : 0) << "\n";
    return 0;
}
