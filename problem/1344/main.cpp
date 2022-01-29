#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int primes[] = {2, 3, 5, 7, 11, 13, 17};
double A, B;
bool used[18][18][18];
vector<vector<vector<double>>> cache(18, vector<vector<double>>(18, vector<double>(18)));

double solve(int pos, int a_score, int b_score) {
    if (pos >= 18) {
        for (int p : primes) {
            if (a_score == p || b_score == p) {
                return 1;
            }
        }
        return 0;
    }
    double& ans = cache[pos][a_score][b_score];
    if (used[pos][a_score][b_score]) {
        return ans;
    }
    ans = A * B * solve(pos + 1, a_score + 1, b_score + 1);
    ans += A * (1.0L - B) * solve(pos + 1, a_score + 1, b_score);
    ans += (1.0L - A) * B * solve(pos + 1, a_score, b_score + 1);
    ans += (1.0L - A) * (1.0L - B) * solve(pos + 1, a_score, b_score);
    used[pos][a_score][b_score] = true;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    A = a / 100.0L;
    B = b / 100.0L;
    cout.precision(7);
    cout << fixed << solve(0, 0, 0) << "\n";
    return 0;
}
