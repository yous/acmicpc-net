#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> times;
priority_queue<int, vector<int>, greater<int>> avail_seats;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> used_seats;
vector<int> seats;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int i;
    int p, q;
    for (i = 0; i < N; i++) {
        cin >> p >> q;
        times.push_back(make_pair(p, q));
    }
    sort(times.begin(), times.end());
    int seat_count = 0;
    seats.push_back(-1);
    for (auto time : times) {
        while (!used_seats.empty()) {
            auto pop_seat = used_seats.top();
            if (time.first > pop_seat.first) {
                avail_seats.push(pop_seat.second);
                used_seats.pop();
            } else {
                break;
            }
        }
        if (avail_seats.empty()) {
            seat_count++;
            avail_seats.push(seat_count);
            seats.push_back(0);
        }
        int seat = avail_seats.top();
        seats[seat]++;
        avail_seats.pop();
        used_seats.push(make_pair(time.second, seat));
    }
    cout << seat_count << "\n";
    for (i = 1; i <= seat_count; i++) {
        cout << seats[i];
        if (i < seat_count) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
