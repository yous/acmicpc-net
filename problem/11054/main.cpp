#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;
vector<int> LIS;
vector<int> LIS_INV;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    LIS.resize(N);
    LIS_INV.resize(N);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A.push_back(num);
    }
    vector<int> cur_seq;
    for (int i = 0; i < N; i++) {
        if (cur_seq.empty() || cur_seq.back() < A[i]) {
            cur_seq.push_back(A[i]);
        } else {
            *lower_bound(cur_seq.begin(), cur_seq.end(), A[i]) = A[i];
        }
        LIS[i] = cur_seq.size();
    }
    cur_seq.clear();
    for (int i = N - 1; i >= 0; i--) {
        if (cur_seq.empty() || cur_seq.back() < A[i]) {
            cur_seq.push_back(A[i]);
        } else {
            *lower_bound(cur_seq.begin(), cur_seq.end(), A[i]) = A[i];
        }
        LIS_INV[i] = cur_seq.size();
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, LIS[i] + LIS_INV[i] - 1);
    }
    cout << ans << "\n";
    return 0;
}
