#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    vector<int> AB(N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB[i * N + j] = A[i] + B[j];
        }
    }
    sort(AB.begin(), AB.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = C[i] + D[j];
            ans += distance(lower_bound(AB.begin(), AB.end(), -sum), upper_bound(AB.begin(), AB.end(), -sum));
        }
    }
    cout << ans << "\n";
    return 0;
}
