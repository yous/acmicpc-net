#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(int L, int W, int H, vector<int>& cubes) {
    if (L == 0 || W == 0 || H == 0) {
        return 0;
    }
    int ans = 0;
    int cur_H = 0;
    for (int i = 19; i >= 0; i--) {
        if (cubes[i] == 0) {
            continue;
        }
        int power = (1 << i);
        if (L >= power && W >= power && H >= power) {
            cur_H = H / power * power;
            long long large_cnt = 1LL * (L / power) * (W / power) * (H / power);
            long long cnt = min(static_cast<long long>(cubes[i]), large_cnt);
            ans += cnt;
            cubes[i] -= cnt;
            long long rem_cnt = large_cnt - cnt;
            if (rem_cnt > 0) {
                if (i == 0) {
                    return -1;
                }
                for (int j = i - 1; j >= 0; j--) {
                    rem_cnt *= 8;
                    if (cubes[j] == 0) {
                        continue;
                    }
                    long long use_cnt = min(static_cast<long long>(cubes[j]), rem_cnt);
                    ans += use_cnt;
                    cubes[j] -= use_cnt;
                    rem_cnt -= use_cnt;
                    if (rem_cnt == 0) {
                        break;
                    }
                }
            }
            if (rem_cnt > 0) {
                return -1;
            }
            int ret = solve(L % power, W, cur_H, cubes);
            if (ret < 0) {
                return -1;
            }
            ans += ret;
            ret = solve(L / power * power, W % power, cur_H, cubes);
            if (ret < 0) {
                return -1;
            }
            ans += ret;
            break;
        }
    }
    if (cur_H == 0) {
        return -1;
    }
    int next_ret = solve(L, W, H - cur_H, cubes);
    if (next_ret < 0) {
        return -1;
    }
    return ans + next_ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int L, W, H;
    cin >> L >> W >> H;
    short N;
    cin >> N;
    vector<int> cubes(20);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A >> cubes[A];
    }
    cout << solve(L, W, H, cubes) << "\n";
    return 0;
}
