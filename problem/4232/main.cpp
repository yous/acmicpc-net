#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }
        short max_cnt = 0;
        map<vector<short>, short> cnt;
        for (int i = 0; i < N; i++) {
            vector<short> courses(5);
            for (short& num : courses) {
                cin >> num;
            }
            sort(courses.begin(), courses.end());
            max_cnt = max(max_cnt, ++cnt[move(courses)]);
        }
        short ans = 0;
        for (auto& [courses, cnt_val] : cnt) {
            if (cnt_val == max_cnt) {
                ans += cnt_val;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
