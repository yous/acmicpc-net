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
        if (num % 2 == 0) {
            ans ^= (num - 2) / 2;
        } else {
            ans ^= (num + 1) / 2;
        }
    }
    cout << (ans == 0 ? "cubelover\n" : "koosaga\n");
    return 0;
}
