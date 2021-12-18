#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<unsigned int, int>> mosquito;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    mosquito.resize(N * 2);
    for (int i = 0; i < N; i++) {
        unsigned int st, ed;
        cin >> st >> ed;
        mosquito[i * 2] = {st, 1};
        mosquito[i * 2 + 1] = {ed, -1};
    }
    sort(mosquito.begin(), mosquito.end());
    int cnt = 0;
    int max_cnt = 0;
    int st = -1;
    int ed = -1;
    bool in_max = false;
    int idx = 0;
    while (idx < N * 2) {
        int time = mosquito[idx].first;
        cnt += mosquito[idx].second;
        while (idx < N * 2 - 1 && mosquito[idx + 1].first == time) {
            idx++;
            cnt += mosquito[idx].second;
        }
        if (max_cnt < cnt) {
            max_cnt = cnt;
            st = time;
            in_max = true;
        } else if (in_max && cnt < max_cnt) {
            ed = time;
            in_max = false;
        }
        idx++;
    }
    cout << max_cnt << "\n";
    cout << st << " " << ed << "\n";
    return 0;
}
