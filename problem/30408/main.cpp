#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, M;
    cin >> N >> M;
    long long min_M = N;
    long long max_M = N;
    while (min_M > M) {
        min_M /= 2;
        max_M = (max_M + 1) / 2;
    }
    if (min_M <= M && max_M >= M) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
