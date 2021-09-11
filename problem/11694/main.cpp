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
    int one_cnt = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        ans ^= num;
        if (num == 1) {
            one_cnt++;
        }
    }
    if (one_cnt == N) {
        cout << (one_cnt % 2 == 0 ? "koosaga\n" : "cubelover\n");
    } else {
        cout << (ans == 0 ? "cubelover\n" : "koosaga\n");
    }
    return 0;
}
