#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    map<int, long long> cashes;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int X, T, C;
        cin >> X >> T >> C;
        long long new_cash = (cashes[X - T] += C);
        if (new_cash > ans) {
            ans = new_cash;
        }
    }
    cout << ans << "\n";
    return 0;
}
