#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int fib_1 = 0;
    int fib_2 = 1;
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0) {
            fib_1 += fib_2;
        } else {
            fib_2 += fib_1;
        }
    }
    if (N % 2 == 0) {
        cout << fib_1 << "\n";
    } else {
        cout << fib_2 << "\n";
    }
    return 0;
}
