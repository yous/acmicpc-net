#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int N;
    vector<int> t;

    SegTree(int n) : N(n), t(n * 2) {}

    void update(int pos, int val) {
        pos += N;
        for (t[pos] += val; pos > 1; pos /= 2) {
            t[pos / 2] = t[pos] + t[pos ^ 1];
        }
    }

    int query(int l, int r) {
        int ans = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if ((l & 1) != 0) {
                ans += t[l++];
            }
            if ((r & 1) != 0) {
                ans += t[--r];
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        vector<pair<int, int>> islands(N);
        for (auto& [x, y] : islands) {
            cin >> x >> y;
        }
        sort(islands.begin(), islands.end(), [&](auto& lhs, auto& rhs) {
            return lhs.second < rhs.second;
        });
        int new_y = 0;
        int prev_y = islands[0].second;
        islands[0].second = new_y;
        for (int i = 1; i < N; i++) {
            if (islands[i].second == prev_y) {
                islands[i].second = new_y;
            } else {
                prev_y = islands[i].second;
                new_y++;
                islands[i].second = new_y;
            }
        }
        sort(islands.begin(), islands.end(), [&](auto& lhs, auto& rhs) {
            if (lhs.first != rhs.first) {
                return lhs.first < rhs.first;
            }
            return lhs.second > rhs.second;
        });
        SegTree st(N);
        long long ans = 0;
        for (auto [x, y] : islands) {
            ans += st.query(y, new_y + 1);
            st.update(y, 1);
        }
        cout << ans << "\n";
    }
    return 0;
}
