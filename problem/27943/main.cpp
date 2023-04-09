#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    cin >> N;
    cout << "? " << (N + 1) / 2 << endl;
    string eggplant;
    cin >> eggplant;
    long long lo = 1;
    long long hi = (N + 1) / 2 - 1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        cout << "? " << mid << endl;
        string photo;
        cin >> photo;
        if (photo == eggplant) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    long long ans_lo = lo;
    lo = (N + 1) / 2 + 1;
    hi = N;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        cout << "? " << mid << endl;
        string photo;
        cin >> photo;
        if (photo == eggplant) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    long long ans_hi = hi;
    cout << "! " << ans_lo << " " << ans_hi << endl;
    return 0;
}
