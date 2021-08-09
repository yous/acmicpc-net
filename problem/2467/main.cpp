#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> liquid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    liquid.resize(N);
    int le_zero = -1;
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
        if (le_zero == -1 && liquid[i] >= 0) {
            le_zero = i;
        }
    }
    if (le_zero == -1) {
        cout << liquid[N - 2] << " " << liquid[N - 1] << "\n";
        return 0;
    } else if (le_zero == 0) {
        cout << liquid[0] << " " << liquid[1] << "\n";
        return 0;
    }
    pair<int, int> ans;
    int min_d = 2e9;
    if (liquid[le_zero] == 0) {
        if (le_zero >= 1) {
            ans = {liquid[le_zero - 1], 0};
            min_d = -ans.first;
        }
    } else {
        if (le_zero >= 2) {
            int new_d = -(liquid[le_zero - 2] + liquid[le_zero - 1]);
            if (new_d < min_d) {
                min_d = new_d;
                ans = {liquid[le_zero - 2], liquid[le_zero - 1]};
            }
        }
    }
    if (le_zero < N - 1) {
        int new_d = liquid[le_zero] + liquid[le_zero + 1];
        if (new_d < min_d) {
            min_d = new_d;
            ans = {liquid[le_zero], liquid[le_zero + 1]};
        }
    }
    int lo = 0;
    while (lo < le_zero) {
        int hi = upper_bound(liquid.begin() + le_zero, liquid.end(), -liquid[lo]) - liquid.begin();
        if (hi < N) {
            int new_d = abs(liquid[lo] + liquid[hi]);
            if (new_d < min_d) {
                min_d = new_d;
                ans = {liquid[lo], liquid[hi]};
                if (min_d == 0) {
                    cout << ans.first << " " << ans.second << "\n";
                    return 0;
                }
            }
        }
        if (lo < hi - 1) {
            int new_d = abs(liquid[lo] + liquid[hi - 1]);
            if (new_d < min_d) {
                min_d = new_d;
                ans = {liquid[lo], liquid[hi - 1]};
                if (min_d == 0) {
                    cout << ans.first << " " << ans.second << "\n";
                    return 0;
                }
            }
        }
        lo++;
    }
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
