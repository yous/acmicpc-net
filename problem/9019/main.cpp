#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short MOD = 10000;
int T;
int A, B;
char cache[10000];

int get_l(int n) {
    return n / 1000 + n % 1000 * 10;
}

int get_r(int n) {
    return n % 10 * 1000 + n / 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> A >> B;
        fill(cache, cache + 10000, 'X');
        cache[A] = 'A';
        queue<short> qu;
        qu.emplace(A);
        bool found = false;
        while (!qu.empty()) {
            int sz = qu.size();
            while (sz-- > 0) {
                short n = qu.front();
                qu.pop();
                if (n == B) {
                    found = true;
                    break;
                }
                int d = n * 2 % MOD;
                int s = (n - 1 + MOD) % MOD;
                int l = get_l(n);
                int r = get_r(n);
                if (cache[d] == 'X') {
                    if (n * 2 == d) {
                        cache[d] = 'D';
                    } else {
                        cache[d] = 'E';
                    }
                    qu.emplace(d);
                }
                if (cache[s] == 'X') {
                    cache[s] = 'S';
                    qu.emplace(s);
                }
                if (cache[l] == 'X') {
                    cache[l] = 'L';
                    qu.emplace(l);
                }
                if (cache[r] == 'X') {
                    cache[r] = 'R';
                    qu.emplace(r);
                }
            }
            if (found) {
                break;
            }
        }
        int cur = B;
        vector<char> ans;
        while (cur != A) {
            char cmd = cache[cur];
            switch (cmd) {
                case 'D':
                    cur /= 2;
                    break;
                case 'E':
                    cur = (cur + MOD) / 2;
                    cmd = 'D';
                    break;
                case 'S':
                    cur = (cur + 1) % MOD;
                    break;
                case 'L':
                    cur = get_r(cur);
                    break;
                case 'R':
                    cur = get_l(cur);
                    break;
            }
            ans.push_back(cmd);
        }
        for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
            cout << *it;
        }
        cout << "\n";
    }
    return 0;
}
