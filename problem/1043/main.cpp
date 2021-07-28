#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> people;
vector<vector<int>> parties;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    people.resize(N, vector<int>(1));
    parties.resize(M, vector<int>(1));
    int truth_cnt;
    cin >> truth_cnt;
    for (int i = 0; i < truth_cnt; i++) {
        int num;
        cin >> num;
        people[num - 1][0] = 1;
    }
    for (int i = 0; i < M; i++) {
        int party_cnt;
        cin >> party_cnt;
        for (int j = 0; j < party_cnt; j++) {
            int num;
            cin >> num;
            parties[i].push_back(num - 1);
            people[num - 1].push_back(i);
        }
    }
    queue<int> party_qu;
    queue<int> person_qu;
    for (int i = 0; i < N; i++) {
        if (people[i][0] == 1) {
            person_qu.push(i);
        }
    }
    while (!person_qu.empty()) {
        int person = person_qu.front();
        person_qu.pop();
        for (int i = 1; i < people[person].size(); i++) {
            int party = people[person][i];
            if (parties[party][0] == 0) {
                parties[party][0] = 1;
                party_qu.push(party);
            }
        }
        while (!party_qu.empty()) {
            int party = party_qu.front();
            party_qu.pop();
            for (int i = 1; i < parties[party].size(); i++) {
                int person = parties[party][i];
                if (people[person][0] == 0) {
                    people[person][0] = 1;
                    person_qu.push(person);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (parties[i][0] == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
