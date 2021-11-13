#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string doc;
string word;
int doc_sz;
int word_sz;

int solve(int idx) {
    if (doc_sz - idx < word_sz) {
        return 0;
    }
    int ans = 0;
    int i = idx;
    while (doc_sz - i >= word_sz) {
        if (doc[i] == word[0]) {
            int offset = 1;
            while (offset < word_sz && doc[i + offset] == word[offset]) {
                offset++;
            }
            if (offset == word_sz) {
                return 1 + solve(i + offset);
            }
        }
        i++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin, doc);
    getline(cin, word);
    doc_sz = doc.size();
    word_sz = word.size();
    cout << solve(0) << "\n";
    return 0;
}
