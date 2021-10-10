#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int W, N;
vector<int> A;
vector<bool> two_sum(400001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> W >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int two = A[i] + A[j];
            if (W - two < 2 || W - two > 400000) {
                continue;
            }
            if (two_sum[W - two]) {
                cout << "YES\n";
                return 0;
            }
        }
        for (int j = 0; j < i; j++) {
            two_sum[A[i] + A[j]] = true;
        }
    }
    cout << "NO\n";
    return 0;
}
