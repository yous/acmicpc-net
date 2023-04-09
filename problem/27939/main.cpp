#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<bool> purple(N);
    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        purple[i] = (ch == 'P');
    }
    short M, K;
    cin >> M >> K;
    bool ans_white = false;
    for (int i = 0; i < M; i++) {
        bool can_white = true;
        for (int j = 0; j < K; j++) {
            short num;
            cin >> num;
            num--;
            if (purple[num]) {
                can_white = false;
            }
        }
        if (can_white) {
            ans_white = true;
        }
    }
    cout << (ans_white ? "W\n" : "P\n");
    return 0;
}
