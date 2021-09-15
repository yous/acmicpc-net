#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int fib[] = {
    1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
    144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
    17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269,
    2178309
};
vector<int> stones;
vector<int> grundy;
vector<int> actions;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int max_num = 1;
    stones.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
        if (max_num < stones[i]) {
            max_num = stones[i];
        }
    }
    grundy.resize(max_num + 1);
    actions.resize(max_num + 1);
    for (int n = 0; n <= max_num; n++) {
        grundy[n] = __builtin_ctz(~actions[n]);
        int bit = (1 << grundy[n]);
        for (int f : fib) {
            if (n + f > max_num) {
                break;
            }
            actions[n + f] |= bit;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans ^= grundy[stones[i]];
    }
    cout << (ans == 0 ? "cubelover\n" : "koosaga\n");
    return 0;
}
