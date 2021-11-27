#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const char TOK = 'a';

struct Trie {
    vector<Trie*> nodes = vector<Trie*>(26);
    Trie* fail_node = nullptr;
    bool end = false;

    void insert(string::const_iterator it, const string::const_iterator send) {
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

    bool find(string::const_iterator it, const string::const_iterator send) {
        if (end) {
            return true;
        }
        if (it == send) {
            return end;
        }
        int idx = *it - TOK;
        Trie*& child = nodes[idx];
        if (child == nullptr) {
            return find_fail_node(idx)->find(next(it), send);
        }
        return child->find(next(it), send);
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
        for (int i = 0; i < 26; i++) {
            if (root->nodes[i] == nullptr) {
                continue;
            }
            root->nodes[i]->fail_node = root;
            qu.emplace(root->nodes[i]);
        }
        while (!qu.empty()) {
            Trie* node = qu.front();
            qu.pop();
            for (int i = 0; i < 26; i++) {
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
    int N, Q;
    cin >> N;
    Trie trie;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        trie.insert(s.begin(), s.end());
    }
    Trie::build_failure_func(&trie);
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string s;
        cin >> s;
        if (trie.find(s.begin(), s.end())) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
