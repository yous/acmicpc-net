#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> groups;
    vector<bool> visited(N + 1);
    int lo = 1;
    int hi = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        visited[num] = true;
        hi = max(hi, num);
        if (num == lo) {
            bool all_have = true;
            for (int j = lo; j <= hi; j++) {
                if (!visited[j]) {
                    all_have = false;
                    lo = j;
                    break;
                }
            }
            if (all_have) {
                groups.emplace_back(hi);
                lo = hi + 1;
                hi = lo;
            }
        }
    }
    if (groups.back() < N) {
        groups.emplace_back(N);
    }
    cout << groups.size() << "\n";
    lo = 1;
    for (int hi : groups) {
        cout << (hi - lo + 1);
        for (int i = lo; i <= hi; i++) {
            cout << " " << i;
        }
        cout << "\n";
        lo = hi + 1;
    }
    return 0;
}
