#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
pair<int, char> counts[1000001];

pair<int, char> solve(int n) {
    if (n == 1) {
        return {0, 0};
    }
    if (counts[n].first != 0) {
        return counts[n];
    }
    pair<int, char> ans = {1 + solve(n - 1).first, 3};
    if (n % 3 == 0) {
        ans = min(ans, {1 + solve(n / 3).first, 1});
    }
    if (n % 2 == 0) {
        ans = min(ans, {1 + solve(n / 2).first, 2});
    }
    counts[n] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    char op;
    cout << solve(N).first << "\n";
    while (N != 1) {
        cout << N << " ";
        op = solve(N).second;
        switch (op) {
            case 1:
                N /= 3;
                break;
            case 2:
                N /= 2;
                break;
            case 3:
                N -= 1;
                break;
        }
    }
    cout << N << "\n";
    return 0;
}
