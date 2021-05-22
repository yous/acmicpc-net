#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int r = 31;
const int M = 1234567891;
int L;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> S;
    int hash_val = 0;
    for (auto it = S.rbegin(); it != S.rend(); it++) {
        hash_val = hash_val * r + *it - 'a' + 1;
        hash_val %= M;
    }
    cout << hash_val << "\n";
    return 0;
}
