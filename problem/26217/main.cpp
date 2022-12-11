#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    double ans = 0;
    short remain = N;
    for (int i = 0; i < N; i++) {
        ans += N / double(remain);
        remain--;
    }
    cout.precision(5);
    cout << fixed << ans << "\n";
    return 0;
}
