#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A, B, C;
vector<int> cache;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B >> C;
    long long prod = A;
    for (int i = 0; i < 31; i++) {
        cache.push_back(prod);
        prod *= prod;
        prod %= C;
    }
    prod = 1;
    while (B > 0) {
        int order = 31 - __builtin_clz(B);
        prod *= cache[order];
        prod %= C;
        B -= (1 << order);
    }
    cout << prod << "\n";
    return 0;
}
