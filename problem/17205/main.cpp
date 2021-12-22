#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string S;
    cin >> S;
    int sz = S.size();
    vector<long long> pow(N);
    long long p = 1;
    for (int i = 0; i < N; i++) {
        pow[i] = p;
        p *= 26;
    }
    long long ans = 0;
    for (int i = 0; i < sz; i++) {
        for (int l = 1; l <= N - i; l++) {
            ans += pow[l - 1] * (S[i] - 'a');
        }
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
