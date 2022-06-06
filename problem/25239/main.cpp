#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void add_time(short& hour, short& minute, short add_h, short add_m) {
    minute += add_m;
    if (minute >= 60) {
        minute -= 60;
        hour++;
    }
    hour += add_h;
    if (hour >= 12) {
        hour %= 12;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short hour, minute;
    char ch;
    cin >> hour >> ch >> minute;
    short cur_pos = hour / 2;
    vector<short> heal(6);
    for (short& num : heal) {
        cin >> num;
    }
    short L;
    cin >> L;
    while (L-- > 0) {
        int S;
        short T;
        cin >> S >> ch >> T;
        string event;
        cin >> event;
        if (event[0] == '^') {
            heal[cur_pos] = 0;
        } else if (event[0] == '1' || event[0] == '3' || event[0] == '5') {
            add_time(hour, minute, 0, (event[0] - '0') * 10);
            cur_pos = hour / 2;
        } else if (event[0] == '2' || event[0] == '4' || event[0] == '9') {
            add_time(hour, minute, event[0] - '0', 0);
            cur_pos = hour / 2;
        }
    }
    short ans = 0;
    for (short num : heal) {
        ans += num;
    }
    if (ans > 100) {
        ans = 100;
    }
    cout << ans << "\n";
    return 0;
}
