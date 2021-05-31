#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int T;
int N;
map<string, short> types;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        string name, type;
        while (N-- > 0) {
            cin >> name >> type;
            types[type]++;
        }
        int ans = 1;
        for (auto& type : types) {
            ans *= type.second + 1;
        }
        cout << ans - 1 << "\n";
        types.clear();
    }
    return 0;
}
