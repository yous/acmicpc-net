#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int max_s = 0;
    int min_e = 100001;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        max_s = max(max_s, s);
        min_e = min(min_e, e);
    }
    if (max_s <= min_e) {
        cout << "0\n";
    } else {
        cout << max_s - min_e << "\n";
    }
    return 0;
}
