#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int M;

struct Trie {
    Trie* c[2] = {};
    int count = 0;

    void insert(int n) {
        Trie* parent = this;
        for (int p = 29; p >= 0; p--) {
            int pos = (n & (1 << p)) >> p;
            if (parent->c[pos] == nullptr) {
                parent->c[pos] = new Trie;
            }
            parent = parent->c[pos];
            parent->count++;
        }
    }

    int find(int n) {
        int ans = 0;
        Trie* parent = this;
        for (int p = 29; p >= 0; p--) {
            int pos = (n & (1 << p)) >> p;
            if (parent->c[pos] == nullptr) {
                pos ^= 1;
            }
            ans += (pos << p);
            parent = parent->c[pos];
        }
        return ans;
    }

    void remove(int n) {
        Trie* parent = this;
        vector<Trie*> dead;
        for (int p = 29; p >= 0; p--) {
            int pos = (n & (1 << p)) >> p;
            Trie* child = parent->c[pos];
            child->count--;
            if (child->count == 0) {
                parent->c[pos] = nullptr;
                dead.push_back(child);
            }
            parent = child;
        }
        for (auto child : dead) {
            delete child;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M;
    Trie trie;
    trie.insert(0);
    for (int i = 0; i < M; i++) {
        int cmd, x;
        cin >> cmd >> x;
        switch (cmd) {
            case 1:
                trie.insert(x);
                break;
            case 2:
                trie.remove(x);
                break;
            case 3:
                cout << (x ^ trie.find(~x)) << "\n";
                break;
        }
    }
    return 0;
}
