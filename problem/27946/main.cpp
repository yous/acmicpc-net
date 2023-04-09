#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> char_to_idx(123);
    for (char ch = 'a'; ch <= 'z'; ch++) {
        char_to_idx[ch] = ch - 'a';
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        char_to_idx[ch] = ch - 'A' + 26;
    }
    for (char ch = '0'; ch <= '9'; ch++) {
        char_to_idx[ch] = ch - '0' + 52;
    }
    unordered_map<string, int> dict;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vector<bool> visited(62);
        auto sz = word.size();
        for (int i = 0; i < sz; i++) {
            char ch = word[i];
            int idx = char_to_idx[ch];
            if (!visited[idx]) {
                visited[idx] = true;
                continue;
            }
            word[i] = '*';
        }
        while (word[sz - 1] == '*') {
            sz--;
        }
        word.resize(sz);
        dict[word]++;
    }
    for (int i = 0; i < M; i++) {
        string word;
        cin >> word;
        vector<bool> visited(62);
        auto sz = word.size();
        int cnt = 0;
        string search;
        for (int i = 0; i < sz; i++) {
            char ch = word[i];
            int idx = char_to_idx[ch];
            if (!visited[idx]) {
                visited[idx] = true;
                search += ch;
            } else {
                search += '*';
                continue;
            }
            auto it = dict.find(search);
            if (it != dict.end()) {
                cnt += it->second;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
