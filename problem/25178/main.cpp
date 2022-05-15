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
    int sz = S.size();
    int cnt[5] = {0};
    for (int i = 1; i < sz - 1; i++) {
        switch (S[i]) {
            case 'a':
                cnt[0]++;
                break;
            case 'e':
                cnt[1]++;
                break;
            case 'i':
                cnt[2]++;
                break;
            case 'o':
                cnt[3]++;
                break;
            case 'u':
                cnt[4]++;
                break;
        }
    }
    string S2;
    cin >> S2;
    if (S2[0] != S[0] || S2[sz - 1] != S[sz - 1]) {
        cout << "NO\n";
        return 0;
    }
    int idx = 1;
    for (int i = 1; i < sz - 1; i++) {
        switch (S2[i]) {
            case 'a':
                cnt[0]--;
                break;
            case 'e':
                cnt[1]--;
                break;
            case 'i':
                cnt[2]--;
                break;
            case 'o':
                cnt[3]--;
                break;
            case 'u':
                cnt[4]--;
                break;
            default:
                while (idx < N - 1 && (S[idx] == 'a' || S[idx] == 'e' || S[idx] == 'i' || S[idx] == 'o' || S[idx] == 'u')) {
                    idx++;
                }
                if (idx == N - 1 || S2[i] != S[idx]) {
                    cout << "NO\n";
                    return 0;
                }
                idx++;
                break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (cnt[i] != 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
