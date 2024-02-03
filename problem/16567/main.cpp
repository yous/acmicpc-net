#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<short> road(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        road[i] = num;
        if (num == 1 && (i == 0 || road[i - 1] == 0)) {
            cnt++;
        }
    }
    for (int i = 0; i < M; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            cout << cnt << "\n";
        } else {
            int num;
            cin >> num;
            num--;
            if (road[num] == 0) {
                road[num] = 1;
                cnt++;
                if (num > 0 && road[num - 1] == 1) {
                    cnt--;
                }
                if (num < N - 1 && road[num + 1] == 1) {
                    cnt--;
                }
            }
        }
    }
    return 0;
}
