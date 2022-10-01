#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    string text;
    cin >> text;
    int lo = 0;
    int hi = 0;
    int len = text.size();
    vector<int> cnt(26);
    short types = 0;
    while (hi < len && types <= N) {
        int idx = text[hi] - 'a';
        if (cnt[idx] == 0) {
            types++;
        }
        cnt[idx]++;
        hi++;
    }
    int ans = hi - lo - (types > N ? 1 : 0);
    while (hi < len) {
        int idx = text[hi] - 'a';
        if (cnt[idx] == 0) {
            types++;
        }
        cnt[idx]++;
        hi++;
        while (lo < hi && types > N) {
            idx = text[lo] - 'a';
            cnt[idx]--;
            if (cnt[idx] == 0) {
                types--;
            }
            lo++;
        }
        ans = max(ans, hi - lo);
    }
    cout << ans << "\n";
    return 0;
}
