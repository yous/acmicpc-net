#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> LIS;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (LIS.empty() || LIS.back() < num) {
            LIS.emplace_back(num);
        } else {
            *lower_bound(LIS.begin(), LIS.end(), num) = num;
        }
    }
    cout << N - LIS.size() << "\n";
    return 0;
}
