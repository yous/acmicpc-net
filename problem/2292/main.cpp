#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int ans = 1;
    int num = 1;
    while (num < N) {
        num += 6 * ans;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
