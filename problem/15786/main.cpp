#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    for (int i = 0; i < M; i++) {
        string postit;
        cin >> postit;
        int sz = postit.size();
        int idx = 0;
        for (int j = 0; j < sz; j++) {
            if (S[idx] == postit[j]) {
                idx++;
            }
            if (idx == N) {
                break;
            }
        }
        if (idx == N) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }
    return 0;
}
