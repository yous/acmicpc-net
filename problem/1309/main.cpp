#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 9901;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<int> prev_count(3);
    vector<int> next_count(3);
    prev_count[0] = 1;
    prev_count[1] = 1;
    prev_count[2] = 1;
    for (int i = 1; i < N; i++) {
        next_count[0] = (prev_count[0] + prev_count[1] + prev_count[2]) % MOD;
        next_count[1] = (prev_count[0] + prev_count[2]) % MOD;
        next_count[2] = (prev_count[0] + prev_count[1]) % MOD;
        swap(prev_count, next_count);
    }
    cout << (prev_count[0] + prev_count[1] + prev_count[2]) % MOD << "\n";
    return 0;
}
