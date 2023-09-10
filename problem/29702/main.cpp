#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        long long N;
        cin >> N;
        int floor = 1;
        long long cnt = 1;
        while (N > cnt) {
            N -= cnt;
            floor++;
            cnt *= 2;
        }
        while (floor >= 1) {
            cout << floor << setfill('0') << setw(18) << N << "\n";
            floor--;
            N = (N + 1) / 2;
        }
    }
    return 0;
}
