#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const short days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Time {
    short year, month, mday, yday;
    short hour, min;

    Time(short y, short mon, short d, short h, short min) : year(y), month(mon), mday(d), hour(h), min(min) {
        yday = 0;
        for (int i = 0; i < month - 1; i++) {
            yday += days[i] + ((year % 4 == 0 && i == 1) ? 1 : 0);
        }
        yday += mday - 1;
    }

    Time& operator+=(const short diff) {
        min += diff % 60;
        if (min >= 60) {
            hour++;
            min -= 60;
        }
        hour += diff / 60;
        if (hour >= 24) {
            mday++;
            yday++;
            hour -= 24;
        }
        if (mday > days[month - 1] + ((year % 4 == 0 && month == 2) ? 1 : 0)) {
            month++;
            mday = 1;
        }
        if (month > 12) {
            year++;
            yday = 0;
            month -= 12;
        }
        return *this;
    }

    bool operator<(const Time& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (yday != other.yday) {
            return yday < other.yday;
        }
        if (hour != other.hour) {
            return hour < other.hour;
        }
        return min < other.min;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        short B, C;
        cin >> B >> C;
        vector<pair<Time, bool>> timeline;
        for (int i = 0; i < B; i++) {
            string code;
            char delim;
            short year, month, day, hour, min;
            cin >> code >> year >> delim >> month >> delim >> day >> hour >> delim >> min;
            Time st_time(year, month, day, hour, min);
            cin >> year >> delim >> month >> delim >> day >> hour >> delim >> min;
            Time ed_time(year, month, day, hour, min);
            ed_time += C;
            timeline.emplace_back(st_time, true);
            timeline.emplace_back(ed_time, false);
        }
        sort(timeline.begin(), timeline.end());
        short ans = 0;
        short cur = 0;
        for (auto& [t, is_in] : timeline) {
            if (is_in) {
                cur++;
            } else {
                cur--;
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
    return 0;
}
