#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while (N % 2 == 0) {
        cout << "2\n";
        N /= 2;
    }
    for (int i = 3; i * i <= N; i += 2) {
        while (N % i == 0) {
            cout << i << "\n";
            N /= i;
        }
    }
    if (N > 1) {
        cout << N << "\n";
    }
    return 0;
}
