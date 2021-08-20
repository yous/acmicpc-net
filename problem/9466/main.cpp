#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
vector<int> students;
vector<bool> in_cycle;
vector<bool> not_cycle;

void dfs(int idx) {
    int next_student = students[idx];
    if (idx == next_student) {
        in_cycle[idx] = true;
        return;
    }
    if (in_cycle[next_student] || not_cycle[next_student]) {
        not_cycle[idx] = true;
        return;
    }
    vector<bool> visited(N);
    int start = idx;
    visited[start] = true;
    int tmp = students[start];
    while (!visited[tmp]) {
        visited[tmp] = true;
        tmp = students[tmp];
    }
    int cycle_start = tmp;
    tmp = start;
    while (tmp != cycle_start) {
        not_cycle[tmp] = true;
        tmp = students[tmp];
    }
    in_cycle[tmp] = true;
    tmp = students[tmp];
    while (tmp != cycle_start) {
        in_cycle[tmp] = true;
        tmp = students[tmp];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        students.clear();
        students.resize(N);
        in_cycle.clear();
        in_cycle.resize(N);
        not_cycle.clear();
        not_cycle.resize(N);
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            students[i] = num - 1;
        }
        for (int i = 0; i < N; i++) {
            if (!in_cycle[i] && !not_cycle[i]) {
                dfs(i);
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (not_cycle[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
