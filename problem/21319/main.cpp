#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> fighters(N);
    for (int& num : fighters) {
        cin >> num;
    }
    if (N == 1) {
        cout << "1\n";
        return 0;
    }
    vector<int> ans;
    int lo = 0;
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (fighters[i] > fighters[i - 1]) {
            ans.emplace_back(i);
            cnt++;
        }
        while (lo < cnt && ans[lo] < i && fighters[ans[lo]] + i - 1 <= fighters[i]) {
            lo++;
        }
    }
    if (lo == cnt) {
        cout << "-1\n";
    } else {
        cout << ans[lo] + 1;
        for (int i = lo + 1; i < cnt; i++) {
            cout << " " << ans[i] + 1;
        }
        cout << "\n";
    }
    return 0;
}
