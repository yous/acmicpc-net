#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string doc;
string word;
int doc_sz;
int word_sz;
vector<int> cache;

int solve(int idx) {
    if (doc_sz - idx < word_sz) {
        return 0;
    }
    int& ans = cache[idx];
    if (ans >= 0) {
        return ans;
    }
    ans = 0;
    int i = idx;
    while (doc_sz - i >= word_sz) {
        if (doc[i] == word[0]) {
            int offset = 1;
            while (offset < word_sz && doc[i + offset] == word[offset]) {
                offset++;
            }
            if (offset == word_sz) {
                ans = max(ans, 1 + solve(i + offset));
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
    cache.resize(doc_sz, -1);
    cout << solve(0) << "\n";
    return 0;
}
