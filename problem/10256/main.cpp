#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dna_sz, marker_sz, lo, hi;

int acgt_idx(char c) {
    switch (c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
    }
    return -1;
}

struct Trie {
    array<Trie*, 4> nodes = {};
    Trie* fail_node = nullptr;
    bool end = false;

    ~Trie() {
        for (int i = 0; i < 4; i++) {
            if (nodes[i] != nullptr) {
                delete nodes[i];
            }
        }
    }

    void insert(const string& s, int idx) {
        if (idx == marker_sz) {
            end = true;
            return;
        }
        Trie*& child = nodes[acgt_idx(s[idx])];
        if (child == nullptr) {
            child = new Trie;
        }
        int next_idx;
        if (idx < lo - 1) {
            next_idx = idx + 1;
        } else if (idx == lo - 1) {
            next_idx = hi - 1;
        } else if (idx == lo) {
            next_idx = hi;
        } else if (idx < hi) {
            next_idx = idx - 1;
        } else {
            next_idx = idx + 1;
        }
        return child->insert(s, next_idx);
    }

    int find(const string& s, int sidx) {
        int ans = 0;
        if (sidx == dna_sz) {
            if (end) {
                ans++;
            }
            return ans;
        }
        if (end) {
            ans++;
        }
        int idx = acgt_idx(s[sidx]);
        Trie*& child = nodes[idx];
        if (child == nullptr) {
            return ans + find_fail_node(idx)->find(s, sidx + 1);
        }
        return ans + child->find(s, sidx + 1);
    }

    Trie* find_fail_node(int idx) {
        Trie* tmp = fail_node;
        while (tmp->fail_node != tmp && tmp->nodes[idx] == nullptr) {
            tmp = tmp->fail_node;
        }
        if (tmp->nodes[idx] != nullptr) {
            tmp = tmp->nodes[idx];
        }
        return tmp;
    }

    static void build_failure_func(Trie* root) {
        queue<Trie*> qu;
        root->fail_node = root;
        for (int i = 0; i < 4; i++) {
            if (root->nodes[i] == nullptr) {
                continue;
            }
            root->nodes[i]->fail_node = root;
            qu.emplace(root->nodes[i]);
        }
        while (!qu.empty()) {
            Trie* node = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                if (node->nodes[i] == nullptr) {
                    continue;
                }
                node->nodes[i]->fail_node = node->find_fail_node(i);
                qu.emplace(node->nodes[i]);
            }
            node->end |= node->fail_node->end;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        int N, M;
        cin >> N >> M;
        Trie trie;
        string dna, marker;
        cin >> dna >> marker;
        dna_sz = dna.size();
        marker_sz = marker.size();
        lo = hi = marker_sz + 1;
        trie.insert(marker, 0);
        for (lo = 0; lo < marker_sz - 1; lo++) {
            for (hi = lo + 2; hi <= marker_sz; hi++) {
                trie.insert(marker, (lo == 0 ? hi - 1 : 0));
            }
        }
        Trie::build_failure_func(&trie);
        cout << trie.find(dna, 0) << "\n";
    }
    return 0;
}
