#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
long long P[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

long long get_p(int n) {
    long long& ans = P[n];
    if (ans != 0) {
        return ans;
    }
    ans = get_p(n - 5) + get_p(n - 1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        cout << get_p(N) << "\n";
    }
    return 0;
}
