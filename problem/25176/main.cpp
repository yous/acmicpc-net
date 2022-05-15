#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        ans *= i;
    }
    cout << ans << "\n";
    return 0;
}
