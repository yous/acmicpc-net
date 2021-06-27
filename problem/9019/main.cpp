#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short INF = 30000;
const short MOD = 10000;
int T;
int A, B;
pair<short, char> cache[10000];

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
        fill(cache, cache + 10000, make_pair(INF, 'X'));
        cache[A].first = 0;
        short step = 0;
        queue<pair<short, char>> qu;
        qu.emplace(A, 'X');
        bool found = false;
        while (!qu.empty()) {
            int sz = qu.size();
            while (sz-- > 0) {
                auto& p = qu.front();
                short n = p.first;
                qu.pop();
                if (n == B) {
                    found = true;
                    break;
                }
                if (cache[n].first < step) {
                    continue;
                }
                int d = n * 2 % MOD;
                int s = (n - 1 + MOD) % MOD;
                int l = get_l(n);
                int r = get_r(n);
                if (step + 1 < cache[d].first) {
                    if (n * 2 == d) {
                        cache[d] = {step + 1, 'D'};
                    } else {
                        cache[d] = {step + 1, 'E'};
                    }
                    qu.emplace(d, 'D');
                }
                if (step + 1 < cache[s].first) {
                    cache[s] = {step + 1, 'S'};
                    qu.emplace(s, 'S');
                }
                if (step + 1 < cache[l].first) {
                    cache[l] = {step + 1, 'L'};
                    qu.emplace(l, 'L');
                }
                if (step + 1 < cache[r].first) {
                    cache[r] = {step + 1, 'R'};
                    qu.emplace(r, 'R');
                }
            }
            if (found) {
                break;
            }
            step++;
        }
        int cur = B;
        vector<char> ans;
        while (cur != A) {
            char cmd = cache[cur].second;
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
