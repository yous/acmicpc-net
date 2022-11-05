#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int diff_square(int a, int b) {
    return (a - b) * (a - b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string YYYYMMDD;
    cin >> YYYYMMDD;
    short N;
    cin >> N;
    string ans = YYYYMMDD;
    int max_bio = 0;
    for (int i = 0; i < N; i++) {
        string yyyymmdd;
        cin >> yyyymmdd;
        int diff = (diff_square(yyyymmdd[0], YYYYMMDD[0]) +
                    diff_square(yyyymmdd[1], YYYYMMDD[1]) +
                    diff_square(yyyymmdd[2], YYYYMMDD[2]) +
                    diff_square(yyyymmdd[3], YYYYMMDD[3])) *
            (diff_square(yyyymmdd[4], YYYYMMDD[4]) +
             diff_square(yyyymmdd[5], YYYYMMDD[5])) *
            (diff_square(yyyymmdd[6], YYYYMMDD[6]) +
             diff_square(yyyymmdd[7], YYYYMMDD[7]));
        if (max_bio < diff) {
            max_bio = diff;
            ans = yyyymmdd;
        } else if (max_bio == diff) {
            ans = min(ans, yyyymmdd);
        }
    }
    cout << ans << "\n";
    return 0;
}
