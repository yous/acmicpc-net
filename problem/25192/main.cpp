#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    set<string> names;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        if (name == "ENTER") {
            names.clear();
        } else if (names.find(name) == names.end()) {
            names.emplace(name);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
