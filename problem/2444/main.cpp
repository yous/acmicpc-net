#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << string(N - i, ' ') << string(i * 2 - 1, '*') << "\n";
    }
    for (int i = N - 1; i >= 1; i--) {
        cout << string(N - i, ' ') << string(i * 2 - 1, '*') << "\n";
    }
    return 0;
}
