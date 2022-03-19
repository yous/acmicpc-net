#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int BASE1 = 1511;
const int BASE2 = 2999;
const int BASE3 = 4999;
const int MOD = int(1e9) + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string SA, SB;
    cin >> SA >> SB;
    short N = SA.size();
    short M = SB.size();
    vector<int> power1(26);
    vector<int> power2(26);
    vector<int> power3(26);
    power1[0] = 1;
    power2[0] = 1;
    power3[0] = 1;
    for (int i = 1; i < 26; i++) {
        power1[i] = 1LL * power1[i - 1] * BASE1 % MOD;
        power2[i] = 1LL * power2[i - 1] * BASE2 % MOD;
        power3[i] = 1LL * power3[i - 1] * BASE3 % MOD;
    }
    vector<int> hash_a1;
    vector<int> hash_a2;
    vector<int> hash_a3;
    for (int i = 0; i < N; i++) {
        int cur1 = 0;
        int cur2 = 0;
        int cur3 = 0;
        for (int j = i; j < N; j++) {
            cur1 = (cur1 + power1[SA[j] - 'a']) % MOD;
            cur2 = (cur2 + power2[SA[j] - 'a']) % MOD;
            cur3 = (cur3 + power3[SA[j] - 'a']) % MOD;
            hash_a1.emplace_back(cur1);
            hash_a2.emplace_back(cur2);
            hash_a3.emplace_back(cur3);
        }
    }
    sort(hash_a1.begin(), hash_a1.end());
    sort(hash_a2.begin(), hash_a2.end());
    sort(hash_a3.begin(), hash_a3.end());
    short ans = 0;
    for (int i = 0; i < M; i++) {
        int cur1 = 0;
        int cur2 = 0;
        int cur3 = 0;
        for (int j = i; j < M; j++) {
            cur1 = (cur1 + power1[SB[j] - 'a']) % MOD;
            cur2 = (cur2 + power2[SB[j] - 'a']) % MOD;
            cur3 = (cur3 + power3[SB[j] - 'a']) % MOD;
            if (binary_search(hash_a1.begin(), hash_a1.end(), cur1) && binary_search(hash_a2.begin(), hash_a2.end(), cur2) && binary_search(hash_a3.begin(), hash_a3.end(), cur3)) {
                ans = max(ans, short(j - i + 1));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
