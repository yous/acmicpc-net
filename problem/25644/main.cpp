#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int ans = 0;
    int cur_buy;
    cin >> cur_buy;
    for (int i = 1; i < N; i++) {
        int price;
        cin >> price;
        ans = max(ans, price - cur_buy);
        if (price < cur_buy) {
            cur_buy = price;
        }
    }
    cout << ans << "\n";
    return 0;
}
