#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> cnt(100001);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cnt[num]++;
    }
    int lo = 1;
    while (lo <= 100000 && cnt[lo] == 0) {
        lo++;
    }
    int hi = 100000;
    while (hi >= 1 && cnt[hi] == 0) {
        hi--;
    }
    int rem = cnt[lo];
    while (lo < hi) {
        if (rem == 0 || cnt[lo + 1] == 0 || rem > cnt[lo + 1]) {
            cout << "-1\n";
            return 0;
        }
        rem = cnt[lo + 1] - rem;
        lo++;
    }
    if (lo == hi && rem == 0) {
        cout << "1\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
