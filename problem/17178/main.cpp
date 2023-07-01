#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    deque<pair<char, short>> tickets(N * 5);
    for (auto& [alpha, num] : tickets) {
        char ch;
        cin >> alpha;
        cin >> ch;
        cin >> num;
    }
    vector<pair<char, short>> waiters;
    waiters.emplace_back(tickets.front());
    tickets.pop_front();
    pair<char, short> last = {'A', 0};
    while (!tickets.empty()) {
        if (!waiters.empty() && tickets.front() > waiters.back()) {
            pair<char, short> next = waiters.back();
            waiters.pop_back();
            if (last > next) {
                cout << "BAD\n";
                return 0;
            }
            last = next;
            continue;
        }
        if (tickets.size() > 1 && tickets[0] > tickets[1]) {
            waiters.emplace_back(tickets.front());
            tickets.pop_front();
        } else {
            pair<char, short> next = tickets.front();
            tickets.pop_front();
            if (last > next) {
                cout << "BAD\n";
                return 0;
            }
            last = next;
        }
    }
    while (!waiters.empty()) {
        pair<char, short> next = waiters.back();
        waiters.pop_back();
        if (last > next) {
            cout << "BAD\n";
            return 0;
        }
        last = next;
    }
    cout << "GOOD\n";
    return 0;
}
