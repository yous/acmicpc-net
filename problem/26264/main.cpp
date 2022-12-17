#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string S;
    cin >> S;
    int idx = 0;
    int bigdata_cnt = 0;
    int security_cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[idx] == 'b') {
            bigdata_cnt++;
            idx += 7;
        } else {
            security_cnt++;
            idx += 8;
        }
    }
    if (bigdata_cnt > security_cnt) {
        cout << "bigdata?\n";
    } else if (security_cnt > bigdata_cnt) {
        cout << "security!\n";
    } else {
        cout << "bigdata? security!\n";
    }
    return 0;
}
