#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long r = 31;
const long long M = 1234567891;
int L;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> S;
    long long hash_val = 0;
    for (auto it = S.rbegin(); it != S.rend(); it++) {
        hash_val = hash_val * r + *it - 'a' + 1;
        hash_val %= M;
    }
    cout << hash_val << "\n";
    return 0;
}
