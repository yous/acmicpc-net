#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    long long ans = N;
    N--;
    int i;
    for (i = 1; i * i <= N; i++) {
        ans += N / i * 2;
    }
    ans -= (i - 1) * (i - 1);
    cout << ans << "\n";
    return 0;
}
