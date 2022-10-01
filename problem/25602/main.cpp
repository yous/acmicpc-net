#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N, K;
int ans = 0;

void solve(int day, int sum, vector<short>& A, vector<vector<short>>& R, vector<vector<short>>& M) {
    if (day == K) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            continue;
        }
        A[i]--;
        for (int j = 0; j < N; j++) {
            if (A[j] == 0) {
                continue;
            }
            A[j]--;
            solve(day + 1, sum + R[day][i] + M[day][j], A, R, M);
            A[j]++;
        }
        A[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    vector<short> A(N);
    for (auto& num : A) {
        cin >> num;
    }
    vector<vector<short>> R(K, vector<short>(N));
    for (auto& row : R) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    vector<vector<short>> M(K, vector<short>(N));
    for (auto& row : M) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    solve(0, 0, A, R, M);
    cout << ans << "\n";
    return 0;
}
