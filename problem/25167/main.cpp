#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M, P;
    cin >> N >> M >> P;
    vector<pair<string, short>> people(M);
    for (auto& [name, idx] : people) {
        cin >> name;
    }
    sort(people.begin(), people.end());
    for (int i = 0; i < M; i++) {
        people[i].second = i;
    }
    vector<vector<pair<short, short>>> times(M, vector<pair<short, short>>(N));
    for (int i = 0; i < P; i++) {
        short num;
        cin >> num;
        string hour;
        short minute;
        getline(cin, hour, ':');
        cin >> minute;
        minute += stoi(hour) * 60;
        string name;
        cin >> name;
        string solve;
        cin >> solve;
        int idx = lower_bound(people.begin(), people.end(), make_pair(name, short(0)))->second;
        auto& [st, ed] = times[idx][num - 1];
        if (solve[0] == 'w') {
            if (st == 0 && ed == 0) {
                st = minute;
            }
        } else {
            if (ed == 0) {
                ed = minute;
            }
        }
    }
    vector<pair<int, short>> scores(M);
    for (int i = 0; i < M; i++) {
        scores[i].second = i;
    }
    for (int num = 0; num < N; num++) {
        vector<pair<int, short>> prob_scores;
        for (int i = 0; i < M; i++) {
            auto [st, ed] = times[i][num];
            if (st != 0 && ed != 0) {
                prob_scores.emplace_back(ed - st, i);
            } else {
                if (st == 0 && ed != 0) {
                    scores[i].first += M + 1;
                } else if (st != 0 && ed == 0) {
                    scores[i].first += M;
                } else {
                    scores[i].first += M + 1;
                }
            }
        }
        sort(prob_scores.begin(), prob_scores.end());
        int cur_score = 1;
        for (auto [score, idx] : prob_scores) {
            scores[idx].first += cur_score;
            cur_score++;
        }
    }
    sort(scores.begin(), scores.end());
    for (int i = 0; i < M; i++) {
        cout << people[scores[i].second].first << "\n";
    }
    return 0;
}
