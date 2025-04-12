#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string line;
    cin >> line;
    int ans = 0;
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            num = num * 10 + line[i] - '0';
        } else {
            ans += num;
            num = 0;
        }
    }
    if (num > 0) {
        ans += num;
    }
    cout << ans << "\n";
    return 0;
}
