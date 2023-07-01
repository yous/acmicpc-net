#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = int(1e9) + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<int> fibo(51);
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i <= N; i++) {
        fibo[i] = (1 + fibo[i - 1] + fibo[i - 2]) % MOD;
    }
    cout << fibo[N] << "\n";
    return 0;
}
