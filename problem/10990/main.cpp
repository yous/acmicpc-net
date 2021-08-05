#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cout << string(N - 1, ' ') << "*\n";
    for (int i = 2; i <= N; i++) {
        cout << string(N - i, ' ') << "*" << string(i * 2 - 3, ' ') << "*\n";
    }
    return 0;
}
