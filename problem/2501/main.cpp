#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> dividers;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    int cnt = 0;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            cnt++;
            if (cnt == K) {
                cout << i << "\n";
                break;
            }
            if (i * i != N) {
                dividers.emplace_back(N / i);
            }
        }
    }
    if (cnt < K) {
        if (cnt + dividers.size() < K) {
            cout << "0\n";
        } else {
            cout << dividers[dividers.size() - (K - cnt)] << "\n";
        }
    }
    return 0;
}
