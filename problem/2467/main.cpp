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
    if (le_zero >= 2) {
        int new_d = -(liquid[le_zero - 2] + liquid[le_zero - 1]);
        if (new_d < min_d) {
            min_d = new_d;
            ans = {liquid[le_zero - 2], liquid[le_zero - 1]};
        }
    }
    if (le_zero < N - 1) {
        int new_d = liquid[le_zero] + liquid[le_zero + 1];
        if (new_d < min_d) {
            min_d = new_d;
            ans = {liquid[le_zero], liquid[le_zero + 1]};
        }
    }
    int lo = le_zero - 1;
    int hi = le_zero;
    while (lo >= 0 && hi < N) {
        int new_d = liquid[lo] + liquid[hi];
        if (new_d == 0) {
            cout << liquid[lo] << " " << liquid[hi] << "\n";
            return 0;
        }
        if (abs(new_d) < min_d) {
            ans = {liquid[lo], liquid[hi]};
            min_d = abs(new_d);
        }
        if (new_d < 0) {
            hi++;
        } else {
            lo--;
        }
    }
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
