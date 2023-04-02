#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<double> nums(N);
    double ans = 0;
    double cur_prod = 0;
    for (auto& num : nums) {
        cin >> num;
        double prod = cur_prod * num;
        cur_prod = max(prod, num);
        ans = max(ans, cur_prod);
    }
    cout.precision(3);
    cout << fixed << ans << "\n";
    return 0;
}
