#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<short> K(M);
    for (auto& num : K) {
        cin >> num;
    }
    vector<bool> checked(N);
    for (auto num : K) {
        int mul = num;
        while (mul <= N) {
            if (!checked[mul - 1]) {
                checked[mul - 1] = true;
            }
            mul += num;
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (checked[i - 1]) {
            sum += i;
        }
    }
    cout << sum << "\n";
    return 0;
}
