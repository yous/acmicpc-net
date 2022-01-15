#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    if (N < 10 || (N < 100 && N % 10 == 0)) {
        cout << "-1\n";
        return 0;
    }
    string N_str = to_string(N);
    int N_sz = N_str.size();
    sort(N_str.rbegin(), N_str.rend());
    vector<bool> in_qu(stoi(N_str) + 1);
    queue<int> qu;
    in_qu[N] = true;
    qu.emplace(N);
    for (int k = 0; k < K; k++) {
        int sz = qu.size();
        while (sz-- > 0) {
            int n = qu.front();
            qu.pop();
            in_qu[n] = false;
            string n_str = to_string(n);
            for (int j = 1; j < N_sz; j++) {
                if (n_str[j] == '0') {
                    continue;
                }
                swap(n_str[0], n_str[j]);
                int new_n = stoi(n_str);
                swap(n_str[0], n_str[j]);
                if (!in_qu[new_n]) {
                    in_qu[new_n] = true;
                    qu.emplace(new_n);
                }
            }
            for (int i = 1; i < N_sz - 1; i++) {
                for (int j = i + 1; j < N_sz; j++) {
                    swap(n_str[i], n_str[j]);
                    int new_n = stoi(n_str);
                    swap(n_str[i], n_str[j]);
                    if (!in_qu[new_n]) {
                        in_qu[new_n] = true;
                        qu.emplace(new_n);
                    }
                }
            }
        }
    }
    int ans = 0;
    while (!qu.empty()) {
        int num = qu.front();
        qu.pop();
        if (ans < num) {
            ans = num;
        }
    }
    cout << ans << "\n";
    return 0;
}
