#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
long long A, B;
int N;
vector<int> factors;
int sz;

long long solve(int idx, int cnt, int mul, long long n) {
    if (idx == sz) {
        if (cnt % 2 == 1) {
            return -(n / mul);
        } else {
            return n / mul;
        }
    }
    long long total = 0;
    total += solve(idx + 1, cnt + 1, mul * factors[idx], n);
    total += solve(idx + 1, cnt, mul, n);
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> A >> B >> N;
        factors.clear();
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                factors.emplace_back(i);
                N /= i;
                while (N % i == 0) {
                    N /= i;
                }
            }
        }
        if (N > 1) {
            factors.emplace_back(N);
        }
        sz = factors.size();
        cout << "Case #" << t << ": " << solve(0, 0, 1, B) - solve(0, 0, 1, A - 1) << "\n";
    }
    return 0;
}
