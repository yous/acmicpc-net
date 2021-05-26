#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int N;
vector<string> words;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    string s;
    while (N-- > 0) {
        cin >> s;
        words.push_back(s);
    }
    sort(words.begin(), words.end(), compare);
    string& prev = words[0];
    for (auto it = words.begin(); it != words.end(); it++) {
        if (it != words.begin() && prev == *it) {
            continue;
        }
        cout << *it << "\n";
        prev = *it;
    }
    return 0;
}
