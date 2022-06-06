#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int trans_idx(vector<int>& transfer_nums, int num) {
    return lower_bound(transfer_nums.begin(), transfer_nums.end(), num) - transfer_nums.begin();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    map<string, int> station_num;
    vector<vector<pair<int, int>>> lines(N);
    vector<vector<int>> stations(200000);
    vector<bool> is_transfer(200000);
    vector<int> transfer_nums;
    vector<vector<pair<int, int>>> line_transfers(N);
    int cur_station = 0;
    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        lines[i].resize(S);
        for (int j = 0; j < S; j++) {
            string name;
            cin >> name;
            int num;
            auto it = station_num.find(name);
            if (it != station_num.end()) {
                num = it->second;
                if (!is_transfer[it->second]) {
                    is_transfer[it->second] = true;
                    transfer_nums.emplace_back(num);
                }
            } else {
                num = station_num[name] = cur_station;
                cur_station++;
            }
            lines[i][j] = {num, j};
            stations[num].emplace_back(i);
        }
        sort(lines[i].begin(), lines[i].end());
    }
    for (int i = 0; i < N; i++) {
        for (auto [num, idx] : lines[i]) {
            if (is_transfer[num]) {
                line_transfers[i].emplace_back(num, idx);
            }
        }
    }
    sort(transfer_nums.begin(), transfer_nums.end());
    int transfers_sz = transfer_nums.size();
    vector<vector<int>> dist(transfers_sz, vector<int>(transfers_sz, INF));
    for (int i = 0; i < transfers_sz; i++) {
        dist[i][i] = 0;
    }
    for (auto& line_transfer : line_transfers) {
        int sz = line_transfer.size();
        for (int i = 0; i < sz; i++) {
            int i_idx = trans_idx(transfer_nums, line_transfer[i].first);
            for (int j = i + 1; j < sz; j++) {
                int j_idx = trans_idx(transfer_nums, line_transfer[j].first);
                dist[i_idx][j_idx] = dist[j_idx][i_idx] = min(dist[i_idx][j_idx], abs(line_transfer[j].second - line_transfer[i].second) * 2);
            }
        }
    }
    for (int k = 0; k < transfers_sz; k++) {
        for (int i = 0; i < transfers_sz; i++) {
            if (dist[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < transfers_sz; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (Q-- > 0) {
        string st_name, ed_name;
        cin >> st_name >> ed_name;
        int st = station_num[st_name];
        int ed = station_num[ed_name];
        if (is_transfer[st] && is_transfer[ed]) {
            int st_idx = trans_idx(transfer_nums, st);
            int ed_idx = trans_idx(transfer_nums, ed);
            int ans = dist[st_idx][ed_idx];
            cout << (ans == INF ? -1 : ans) << "\n";
        } else if (is_transfer[st] || is_transfer[ed]) {
            if (is_transfer[ed]) {
                swap(st, ed);
            }
            int st_idx = trans_idx(transfer_nums, st);
            int ed_line = stations[ed][0];
            int ed_line_idx = lower_bound(lines[ed_line].begin(), lines[ed_line].end(), make_pair(ed, 0))->second;
            int ans = INF;
            for (auto [num, idx] : line_transfers[ed_line]) {
                int ed_trans_idx = trans_idx(transfer_nums, num);
                int d = dist[st_idx][ed_trans_idx];
                if (d == INF) {
                    continue;
                }
                ans = min(ans, d + abs(ed_line_idx - idx) * 2);
            }
            cout << (ans == INF ? -1 : ans) << "\n";
        } else {
            int st_line = stations[st][0];
            int ed_line = stations[ed][0];
            int st_line_idx = lower_bound(lines[st_line].begin(), lines[st_line].end(), make_pair(st, 0))->second;
            int ed_line_idx = lower_bound(lines[ed_line].begin(), lines[ed_line].end(), make_pair(ed, 0))->second;
            int ans = INF;
            if (st_line == ed_line) {
                ans = abs(ed_line_idx - st_line_idx) * 2;
            }
            for (auto [st_num, st_idx] : line_transfers[st_line]) {
                int st_trans_idx = trans_idx(transfer_nums, st_num);
                for (auto [ed_num, ed_idx] : line_transfers[ed_line]) {
                    int ed_trans_idx = trans_idx(transfer_nums, ed_num);
                    int d = dist[st_trans_idx][ed_trans_idx];
                    if (d == INF) {
                        continue;
                    }
                    ans = min(ans, d + abs(st_line_idx - st_idx) * 2 + abs(ed_line_idx - ed_idx) * 2);
                }
            }
            cout << (ans == INF ? -1 : ans) << "\n";
        }
    }
    return 0;
}
