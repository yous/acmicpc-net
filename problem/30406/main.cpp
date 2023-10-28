#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calc_pairs(int num1, int num2, vector<int>& presents) {
    int cnt = min(presents[num1], presents[num2]);
    presents[num1] -= cnt;
    presents[num2] -= cnt;
    return (num1 ^ num2) * cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> presents(4);
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        presents[num]++;
    }
    int ans = 0;
    ans += calc_pairs(0, 3, presents);
    ans += calc_pairs(1, 2, presents);
    ans += calc_pairs(0, 2, presents);
    ans += calc_pairs(1, 3, presents);
    ans += calc_pairs(0, 1, presents);
    ans += calc_pairs(2, 3, presents);
    cout << ans << "\n";
    return 0;
}
