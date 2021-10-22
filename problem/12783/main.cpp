#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int N, M;
vector<bool> cards(10);
vector<int> cache(1000001);

bool check(int num) {
    while (num > 0) {
        if (!cards[num % 10]) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int solve(int num) {
    int& ans = cache[num];
    if (ans >= -1) {
        return ans;
    }
    if (check(num)) {
        return ans = 0;
    }
    ans = 20;
    for (int i = 2; i * i <= num; i++) {
        if (num % i != 0 || solve(i) != 0) {
            continue;
        }
        int tmp = solve(num / i);
        if (tmp != -1) {
            ans = min(ans, 1 + tmp);
        }
    }
    if (ans == 20) {
        ans = -1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        fill(cards.begin(), cards.end(), false);
        fill(cache.begin(), cache.end(), -2);
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            cards[num] = true;
        }
        cin >> M;
        for (int i = 0; i < M; i++) {
            int K;
            cin >> K;
            cout << solve(K) << "\n";
        }
    }
    return 0;
}
