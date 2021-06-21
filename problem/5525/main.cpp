#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> S;
    int cnt = 0;
    int idx = 0;
    while (idx < M) {
        if (S[idx] == 'I') {
            int num = 0;
            while (idx < M - 2 && S[idx + 1] == 'O' && S[idx + 2] == 'I') {
                num++;
                idx += 2;
            }
            if (num >= N) {
                cnt += num - N + 1;
            }
        }
        idx++;
    }
    cout << cnt << "\n";
    return 0;
}
