#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, A, B;
    cin >> N >> A >> B;
    A--;
    B--;
    queue<pair<int, int>> qu;
    int day = 0;
    int jump = 1;
    qu.emplace(A, B);
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            auto [a, b] = qu.front();
            qu.pop();
            if (a == b) {
                cout << day << "\n";
                return 0;
            }
            if (abs(b - a) % (jump * 2) != 0) {
                continue;
            }
            if (a - jump >= 0) {
                if (b - jump >= 0) {
                    qu.emplace(a - jump, b - jump);
                }
                if (b + jump < N) {
                    qu.emplace(a - jump, b + jump);
                }
            }
            if (a + jump < N) {
                if (b - jump >= 0) {
                    qu.emplace(a + jump, b - jump);
                }
                if (b + jump < N) {
                    qu.emplace(a + jump, b + jump);
                }
            }
        }
        day++;
        jump *= 2;
    }
    cout << "-1\n";
    return 0;
}
