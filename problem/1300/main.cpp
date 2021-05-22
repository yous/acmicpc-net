#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long N, k;

long long le_count(long long num) {
    int i;
    long long count = 0;
    for (i = 1; i <= N; i++) {
        count += min(N, num / i);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> k;
    long long lo = 1;
    long long hi = N * N;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (le_count(mid) < k) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo << "\n";
    return 0;
}
