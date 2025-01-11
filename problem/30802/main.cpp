#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> sizes(6);
    for (auto& num : sizes) {
        cin >> num;
    }
    int T, P;
    cin >> T >> P;
    int t_cnt = 0;
    for (auto num : sizes) {
        t_cnt += num / T + (num % T > 0 ? 1 : 0);
    }
    cout << t_cnt << "\n";
    cout << N / P << " " << N % P << "\n";
    return 0;
}
