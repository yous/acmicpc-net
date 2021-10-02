#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            cnt++;
        }
        if (cnt == K) {
            cout << i << "\n";
            break;
        }
    }
    if (cnt < K) {
        cout << "0\n";
    }
    return 0;
}
