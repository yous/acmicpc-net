#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& num : A) {
        cin >> num;
    }
    if (N >= 513) {
        cout << "Yes\n";
        return 0;
    }
    sort(A.begin(), A.end());
    vector<bool> visited(1 << 17);
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int xor_num = A[i] ^ A[j];
            if (visited[xor_num]) {
                cout << "Yes\n";
                return 0;
            }
            visited[xor_num] = true;
        }
    }
    cout << "No\n";
    return 0;
}
