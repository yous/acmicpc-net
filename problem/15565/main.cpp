#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<bool> dolls(N);
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        dolls[i] = (num == 1);
    }
    int st = 0;
    int ed = 0;
    int cnt = 0;
    int ans = N + 1;
    while (st < N) {
        while (ed < N && cnt < K) {
            if (dolls[ed]) {
                cnt++;
            }
            ed++;
        }
        if (cnt < K) {
            break;
        }
        ans = min(ans, ed - st);
        if (dolls[st]) {
            cnt--;
        }
        st++;
    }
    if (ans > N) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
