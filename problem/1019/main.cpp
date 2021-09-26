#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
long long cnt[10];

void cnt_num(int n, int power) {
    while (n > 0) {
        cnt[n % 10] += power;
        n /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int lo = 1;
    int hi = N;
    int power = 1;
    while (lo <= hi) {
        while (lo % 10 != 0 && lo <= hi) {
            cnt_num(lo++, power);
        }
        if (lo > hi) {
            break;
        }
        while (hi % 10 != 9 && lo <= hi) {
            cnt_num(hi--, power);
        }
        if (lo > hi) {
            break;
        }
        int num = (hi - lo + 1) / 10 * power;
        for (int i = 0; i < 10; i++) {
            cnt[i] += num;
        }
        lo /= 10;
        hi /= 10;
        power *= 10;
    }
    cout << cnt[0];
    for (int i = 1; i < 10; i++) {
        cout << " " << cnt[i];
    }
    cout << "\n";
    return 0;
}
