#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, R, C;

int solve(int y, int x, int size) {
    if (size == 1) {
        return 0;
    }
    if (y < size / 2 && x < size / 2) {
        return solve(y, x, size / 2);
    } else if (y < size / 2 && x >= size / 2) {
        return (size / 2) * (size / 2) + solve(y, x - size / 2, size / 2);
    } else if (y >= size / 2 && x < size / 2) {
        return (size / 2) * (size / 2) * 2 + solve(y - size / 2, x, size / 2);
    } else {
        return (size / 2) * (size / 2) * 3 + solve(y - size / 2, x - size / 2, size / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> R >> C;
    cout << solve(R, C, 1 << N) << "\n";
    return 0;
}
