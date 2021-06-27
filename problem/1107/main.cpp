#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool broken[10];

int make_upper(int n) {
    string n_str = to_string(n);
    int sz = n_str.size();
    int idx = 0;
    while (idx < sz && !broken[n_str[idx] - '0']) {
        idx++;
    }
    if (idx == sz) {
        return n;
    }
    while (idx >= 0 && broken[n_str[idx] - '0']) {
        if (n_str[idx] < '9') {
            n_str[idx]++;
        } else {
            idx--;
            while (idx >= 0 && n_str[idx] == '9') {
                idx--;
            }
            if (idx == -1) {
                idx++;
                n_str.insert(idx, 1, '1');
            } else {
                n_str[idx]++;
            }
        }
    }
    int first_digit = 0;
    while (broken[first_digit]) {
        first_digit++;
    }
    sz = n_str.size();
    for (int i = idx + 1; i < sz; i++) {
        n_str[i] = first_digit + '0';
    }
    int upper = 0;
    for (int i = 0; i < sz; i++) {
        upper = upper * 10 + n_str[i] - '0';
    }
    return upper;
}

int make_lower(int n) {
    string n_str = to_string(n);
    int sz = n_str.size();
    int idx = 0;
    while (idx < sz && !broken[n_str[idx] - '0']) {
        idx++;
    }
    if (idx == sz) {
        return n;
    }
    while (idx >= 0 && broken[n_str[idx] - '0']) {
        if (n_str[idx] > '0') {
            n_str[idx]--;
        } else {
            idx--;
            while (idx >= 0 && n_str[idx] == '0') {
                idx--;
            }
            if (idx == -1) {
                break;
            }
            n_str[idx]--;
        }
    }
    if (idx == -1) {
        idx += 2;
    } else {
        idx++;
    }
    int last_digit = 9;
    while (broken[last_digit]) {
        last_digit--;
    }
    for (int i = idx; i < sz; i++) {
        n_str[i] = last_digit + '0';
    }
    int lower = 0;
    for (int i = 0; i < sz; i++) {
        lower = lower * 10 + n_str[i] - '0';
    }
    if (lower == 0 && broken[0]) {
        return -1;
    }
    return lower;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        broken[num] = true;
    }
    int ans = abs(N - 100);
    if (M == 0) {
        ans = min(ans, static_cast<int>(to_string(N).size()));
    } else if (M < 10) {
        if (M == 9 && !broken[0]) {
            ans = min(ans, 1 + N);
        } else {
            int upper = make_upper(N);
            ans = min(ans, static_cast<int>(to_string(upper).size()) + upper - N);
            int lower = make_lower(N);
            if (lower >= 0) {
                ans = min(ans, static_cast<int>(to_string(lower).size()) + N - lower);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
