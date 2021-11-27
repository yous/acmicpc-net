#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const char TOK = 'a';

struct Trie {
    vector<Trie*> nodes = vector<Trie*>(26);
    bool end = false;

    void insert(string::iterator it, string::iterator send) {
        if (it == send) {
            end = true;
            return;
        }
        Trie*& child = nodes[*it - TOK];
        if (child == nullptr) {
            child = new Trie;
        }
        child->insert(next(it), send);
    }

    bool find(string::iterator it, string::iterator send) {
        if (it == send) {
            return end;
        }
        Trie*& child = nodes[*it - TOK];
        if (child == nullptr) {
            return false;
        }
        return child->find(next(it), send);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    Trie trie;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        trie.insert(s.begin(), s.end());
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if (trie.find(s.begin(), s.end())) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
