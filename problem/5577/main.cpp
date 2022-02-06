#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int boom(int lo, int hi, vector<pair<int, int>>& balls, int sz) {
    int cnt = 0;
    while (lo >= 0 && hi < sz && balls[lo].first == balls[hi].first) {
        if (balls[lo].second + balls[hi].second < 4) {
            break;
        }
        cnt += balls[lo].second + balls[hi].second;
        lo--;
        hi++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> balls;
    int prev_color;
    cin >> prev_color;
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        int color;
        cin >> color;
        if (prev_color == color) {
            cnt++;
        } else {
            balls.emplace_back(prev_color, cnt);
            prev_color = color;
            cnt = 1;
        }
    }
    balls.emplace_back(prev_color, cnt);
    int sz = balls.size();
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        auto [color, num] = balls[i];
        int above = (i > 0 ? balls[i - 1].second : 0);
        int below = (i < sz - 1 ? balls[i + 1].second : 0);
        if (num == 1) {
            if (above > 0 && below > 0 && balls[i - 1].first == balls[i + 1].first) {
                if (balls[i - 1].second + balls[i + 1].second + 1 < 4) {
                    continue;
                }
                int cnt = above + below + 1;
                cnt += boom(i - 2, i + 2, balls, sz);
                ans = max(ans, cnt);
                continue;
            }
            if (above == 3) {
                int cnt = above + 1;
                cnt += boom(i - 2, i + 1, balls, sz);
                ans = max(ans, cnt);
            }
            if (below == 3) {
                int cnt = below + 1;
                cnt += boom(i - 1, i + 2, balls, sz);
                ans = max(ans, cnt);
            }
            continue;
        }
        if (above == 3) {
            int cnt = above + 1;
            int lo = i - 2;
            if (lo >= 0 && balls[lo].first == color && balls[lo].second + num - 1 >= 4) {
                cnt += balls[lo].second + num - 1;
                lo--;
                int hi = i + 1;
                cnt += boom(lo, hi, balls, sz);
            }
            ans = max(ans, cnt);
        }
        if (below == 3) {
            int cnt = below + 1;
            int hi = i + 2;
            if (hi < sz && color == balls[hi].first && num - 1 + balls[hi].second >= 4) {
                cnt += num - 1 + balls[hi].second;
                hi++;
                int lo = i - 1;
                cnt += boom(lo, hi, balls, sz);
            }
            ans = max(ans, cnt);
        }
    }
    cout << N - ans << "\n";
    return 0;
}
