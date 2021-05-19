#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N-- > 0) {
        string s;
        cin >> s;
        int score = 0;
        int ok_num = 0;
        for (char c : s) {
            switch (c) {
                case 'X':
                    ok_num = 0;
                    break;
                case 'O':
                    ok_num++;
                    score += ok_num;
                    break;
            }
        }
        cout << score << "\n";
    }
    return 0;
}
