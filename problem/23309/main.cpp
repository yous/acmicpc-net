#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> unique_map(1000001);
    int first_num;
    cin >> first_num;
    int prev_num = first_num;
    for (int i = 1; i < N; i++) {
        int num;
        cin >> num;
        unique_map[num].first = prev_num;
        unique_map[prev_num].second = num;
        prev_num = num;
    }
    unique_map[prev_num].second = first_num;
    unique_map[first_num].first = prev_num;
    for (int m = 0; m < M; m++) {
        char cmd1, cmd2;
        cin >> cmd1 >> cmd2;
        if (cmd1 == 'B') {
            int i, j;
            cin >> i >> j;
            if (cmd2 == 'N') {
                int i_next = unique_map[i].second;
                cout << i_next << "\n";
                unique_map[j].first = i;
                unique_map[j].second = i_next;
                unique_map[i_next].first = j;
                unique_map[i].second = j;
            } else {
                int i_prev = unique_map[i].first;
                cout << i_prev << "\n";
                unique_map[j].first = i_prev;
                unique_map[j].second = i;
                unique_map[i_prev].second = j;
                unique_map[i].first = j;
            }
        } else {
            int i;
            cin >> i;
            if (cmd2 == 'N') {
                int i_next = unique_map[i].second;
                cout << i_next << "\n";
                unique_map[unique_map[i_next].second].first = i;
                unique_map[i].second = unique_map[i_next].second;
            } else {
                int i_prev = unique_map[i].first;
                cout << i_prev << "\n";
                unique_map[i].first = unique_map[i_prev].first;
                unique_map[unique_map[i_prev].first].second = i;
            }
        }
    }
    return 0;
}
