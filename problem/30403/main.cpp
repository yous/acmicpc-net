#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    string rainbow("roygbiv");
    unordered_map<char, bool> visited;
    for (auto ch : rainbow) {
        visited[ch] = false;
        visited[ch - 'a' + 'A'] = false;
    }
    string S;
    cin >> S;
    for (auto ch : S) {
        visited[ch] = true;
    }
    bool lower_ok = true;
    bool upper_ok = true;
    for (auto ch : rainbow) {
        if (!visited[ch]) {
            lower_ok = false;
        }
        if (!visited[ch - 'a' + 'A']) {
            upper_ok = false;
        }
    }
    if (lower_ok) {
        if (upper_ok) {
            cout << "YeS\n";
        } else {
            cout << "yes\n";
        }
    } else {
        if (upper_ok) {
            cout << "YES\n";
        } else {
            cout << "NO!\n";
        }
    }
    return 0;
}
