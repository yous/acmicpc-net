#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool solve(int idx, int sum, int* cnt) {
    if (sum == 4) {
        return true;
    }
    if (idx >= 7) {
        return false;
    }
    int num = cnt[idx];
    for (int i = 0; i <= num; i++) {
        if (solve(idx + 1, (sum + idx * i) % 7, cnt)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    int cnt[7] = {0};
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cnt[num % 7]++;
    }
    if (cnt[1] >= 4 || cnt[2] >= 2 || cnt[3] >= 6 || cnt[4] >= 1 || cnt[5] >= 5 || cnt[6] >= 3) {
        cout << "YES\n";
        return 0;
    }
    if (solve(1, 0, cnt)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
