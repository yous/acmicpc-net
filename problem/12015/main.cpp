#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;
set<int> cur_seq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        auto it = cur_seq.lower_bound(num);
        if (it != cur_seq.end()) {
            it = cur_seq.erase(it);
            cur_seq.insert(it, num);
        } else {
            cur_seq.insert(it, num);
        }
    }
    cout << cur_seq.size() << "\n";
    return 0;
}
