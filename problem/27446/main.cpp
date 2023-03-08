#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<bool> paper(N);
    for (int i = 0; i < M; i++) {
        short num;
        cin >> num;
        paper[num - 1] = true;
    }
    int seg_cnt = 0;
    int paper_cnt = 0;
    int idx = 0;
    while (idx < N && paper[idx]) {
        idx++;
    }
    while (idx < N) {
        while (idx < N && !paper[idx]) {
            if (seg_cnt == 0) {
                seg_cnt++;
            }
            paper_cnt++;
            idx++;
        }
        if (idx + 2 < N && !paper[idx + 2]) {
            paper_cnt += 3;
            idx += 3;
        } else if (idx + 1 < N && !paper[idx + 1]) {
            paper_cnt += 2;
            idx += 2;
        } else {
            while (idx < N && paper[idx]) {
                idx++;
            }
            if (idx >= N) {
                break;
            }
            seg_cnt++;
            paper_cnt++;
            idx++;
        }
    }
    cout << 5 * seg_cnt + 2 * paper_cnt << "\n";
    return 0;
}
