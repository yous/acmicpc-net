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
        cout << string(N - i, ' ') << "*";
        for (int j = 1; j < i; j++) {
            cout << " *";
        }
        cout << "\n";
    }
    return 0;
}
