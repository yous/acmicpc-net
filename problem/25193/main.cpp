#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int C_cnt = 0;
    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        if (ch == 'C') {
            C_cnt++;
        }
    }
    cout << N / (N - C_cnt + 1) << "\n";
    return 0;
}
