#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short hp1, hp2;
short d1, d2, d3, d4;
short M;
vector<short> attacks(301, 0);
short ans_time = 301;
short ans_jax_hp = 0;
vector<pair<short, bool>> ans;

void solve(short time, short jax_hp, short fiona_hp, vector<pair<short, bool>>& actions, vector<vector<vector<bool>>>& visited) {
    if (jax_hp <= 0) {
        return;
    }
    if (fiona_hp <= 0) {
        return;
    }
    if (time > 300) {
        return;
    }
    if (visited[time][jax_hp][fiona_hp]) {
        return;
    }
    visited[time][jax_hp][fiona_hp] = true;
    if (time + 4 <= 300 && attacks[time + 4] != -1) {
        short next_fiora_damage = 0;
        for (int i = 0; i <= 4; i++) {
            if (attacks[time + i] < 0) {
                continue;
            }
            next_fiora_damage += attacks[time + i];
        }
        if (next_fiora_damage < jax_hp) {
            actions.emplace_back(time, false);
            if (fiona_hp - d1 <= 0) {
                if (time + 4 < ans_time || (time + 4 == ans_time && jax_hp - next_fiora_damage > ans_jax_hp)) {
                    ans_time = time + 4;
                    ans_jax_hp = jax_hp - next_fiora_damage;
                    ans = actions;
                }
            } else {
                solve(time + 5, jax_hp - next_fiora_damage, fiona_hp - d1, actions, visited);
            }
            actions.pop_back();
        }
    }
    if (time + 14 <= 300) {
        short next_fiora_damage = 0;
        if (attacks[time + 14] >= 0) {
            next_fiora_damage = attacks[time + 14];
        }
        if (next_fiora_damage < jax_hp) {
            actions.emplace_back(time, true);
            if (attacks[time + 14] != -1) {
                if (fiona_hp - d2 <= 0) {
                    if (time + 14 < ans_time || (time + 14 == ans_time && jax_hp - next_fiora_damage > ans_jax_hp)) {
                        ans_time = time + 14;
                        ans_jax_hp = jax_hp - next_fiora_damage;
                        ans = actions;
                    }
                }
                solve(time + 15, jax_hp - next_fiora_damage, fiona_hp - d2, actions, visited);
            } else {
                solve(time + 15, jax_hp - next_fiora_damage, fiona_hp, actions, visited);
            }
            actions.pop_back();
        }
    }
    short next_fiora_damage = 0;
    if (attacks[time] >= 0) {
        next_fiora_damage = attacks[time];
    }
    if (next_fiora_damage < jax_hp) {
        solve(time + 1, jax_hp - next_fiora_damage, fiona_hp, actions, visited);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> hp1 >> hp2;
    cin >> d1 >> d2 >> d3 >> d4;
    cin >> M;
    for (int i = 0; i < M; i++) {
        short frame;
        string attack;
        cin >> frame >> attack;
        if (attack[0] == 'a') {
            if (frame + 4 <= 300) {
                attacks[frame + 4] = d3;
            }
        } else {
            for (int i = 0; i < 9; i++) {
                if (frame + i > 300) {
                    break;
                }
                attacks[frame + i] = -1;
            }
            if (frame + 9 <= 300) {
                attacks[frame + 9] = d4;
            }
        }
    }
    vector<vector<vector<bool>>> visited(301, vector<vector<bool>>(301, vector<bool>(301, false)));
    vector<pair<short, bool>> actions;
    solve(0, hp1, hp2, actions, visited);
    if (ans_jax_hp == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto [frame, attack] : ans) {
            cout << frame << " " << (attack ? "counter strike\n" : "attack\n");
        }
    }
    return 0;
}
