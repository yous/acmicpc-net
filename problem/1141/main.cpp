#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    set<string> words;
    string word;
    cin >> word;
    words.emplace(word);
    for (int i = 1; i < N; i++) {
        string word;
        cin >> word;
        auto sz = word.size();
        auto it = words.lower_bound(word);
        if (it != words.end()) {
            auto sz_o = (*it).size();
            bool is_prefix = true;
            for (int j = 0; j < min(sz, sz_o); j++) {
                if (word[j] != (*it)[j]) {
                    is_prefix = false;
                    break;
                }
            }
            if (is_prefix) {
                if (sz > sz_o) {
                    words.erase(it);
                    words.emplace(word);
                }
                continue;
            }
        }
        if (it != words.begin()) {
            auto prev_it = prev(it);
            auto sz_o = (*prev_it).size();
            bool is_prefix = true;
            for (int j = 0; j < min(sz, sz_o); j++) {
                if (word[j] != (*prev_it)[j]) {
                    is_prefix = false;
                    break;
                }
            }
            if (is_prefix) {
                if (sz > sz_o) {
                    words.erase(prev_it);
                    words.emplace(word);
                }
                continue;
            }
        }
        words.emplace(word);
    }
    cout << words.size() << "\n";
    return 0;
}
