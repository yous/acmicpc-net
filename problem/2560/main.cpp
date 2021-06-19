#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;
int A, B, D, N;
deque<int> until_a;
deque<int> until_b;
deque<int> until_d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B >> D >> N;
    int sum_a = 0;
    int sum_b = 0;
    int sum_d = 0;
    sum_a += 1;
    until_a.push_back(1);
    int day = 0;
    while (day < N) {
        if (until_d.size() >= D - B) {
            sum_d -= until_d.back();
            until_d.pop_back();
        }
        if (until_b.size() >= B - A) {
            int back = until_b.back();
            sum_d += back;
            until_d.push_front(back);
            sum_b -= back;
            until_b.pop_back();
        }
        if (until_a.size() >= A) {
            int back = until_a.back();
            sum_b += back;
            until_b.push_front(back);
            sum_a -= back;
            until_a.pop_back();
        }
        sum_a += sum_b % MOD;
        until_a.push_front(sum_b % MOD);
        day++;
    }
    cout << (sum_a % MOD + sum_b % MOD + sum_d % MOD) % MOD << "\n";
    return 0;
}
