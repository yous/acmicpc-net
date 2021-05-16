#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
long long times[100000];

bool check(long long time) {
    long long passed = 0;
    for (int i = 0; i < N; i++) {
        passed += time / times[i];
    }
    return passed >= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> times[i];
    }
    long long l, r;
    l = 1;
    r = times[0] * M;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (!check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l << "\n";
    return 0;
}
