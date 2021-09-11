#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        ans ^= num;
    }
    if (ans == 0) {
        cout << "cubelover\n";
    } else {
        cout << "koosaga\n";
    }
    return 0;
}
