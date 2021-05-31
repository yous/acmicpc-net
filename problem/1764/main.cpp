#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, M;
set<string> unheard;
set<string> unknown;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    string name;
    while (N-- > 0) {
        cin >> name;
        unheard.insert(name);
    }
    while (M-- > 0) {
        cin >> name;
        if (unheard.find(name) != unheard.end()) {
            unknown.insert(name);
        }
    }
    cout << unknown.size() << "\n";
    for (const string& name : unknown) {
        cout << name << "\n";
    }
    return 0;
}
