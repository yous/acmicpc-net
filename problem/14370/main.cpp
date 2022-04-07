#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const string names[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void remove_digit(int digit, int cnt, short alpha[26]) {
    if (cnt == 0) {
        return;
    }
    for (char ch : names[digit]) {
        alpha[ch - 'A'] -= cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    for (short t = 1; t <= T; t++) {
        string S;
        cin >> S;
        short alpha[26] = {0};
        for (char ch : S) {
            alpha[ch - 'A']++;
        }
        short ans[10] = {0};
        short cnt = alpha['Z' - 'A'];
        remove_digit(0, cnt, alpha);
        ans[0] = cnt;
        cnt = alpha['W' - 'A'];
        remove_digit(2, cnt, alpha);
        ans[2] = cnt;
        cnt = alpha['U' - 'A'];
        remove_digit(4, cnt, alpha);
        ans[4] = cnt;
        cnt = alpha['O' - 'A'];
        remove_digit(1, cnt, alpha);
        ans[1] = cnt;
        cnt = alpha['X' - 'A'];
        remove_digit(6, cnt, alpha);
        ans[6] = cnt;
        cnt = alpha['S' - 'A'];
        remove_digit(7, cnt, alpha);
        ans[7] = cnt;
        cnt = alpha['V' - 'A'];
        remove_digit(5, cnt, alpha);
        ans[5] = cnt;
        cnt = alpha['G' - 'A'];
        remove_digit(8, cnt, alpha);
        ans[8] = cnt;
        cnt = alpha['H' - 'A'];
        remove_digit(3, cnt, alpha);
        ans[3] = cnt;
        cnt = alpha['I' - 'A'];
        remove_digit(9, cnt, alpha);
        ans[9] = cnt;
        cout << "Case #" << t << ": ";
        for (int digit = 0; digit <= 9; digit++) {
            for (int i = 0; i < ans[digit]; i++) {
                cout << digit;
            }
        }
        cout << "\n";
    }
    return 0;
}
