#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string solve(long long x, long long y, long long power) {
    if (power == 2) {
        if (y == 0) {
            return (x == 0 ? "3" : "4");
        } else {
            return (x == 0 ? "2" : "1");
        }
    }
    power /= 2;
    if (y >= power) {
        if (x >= power) {
            return "1" + solve(x - power, y - power, power);
        } else {
            return "2" + solve(x, y - power, power);
        }
    } else {
        if (x >= power) {
            return "4" + solve(x - power, y, power);
        } else {
            return "3" + solve(x, y, power);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short D;
    cin >> D;
    string ID;
    cin >> ID;
    long long X, Y;
    cin >> X >> Y;
    long long power = (1LL << D);
    long long orig_X = 0;
    long long orig_Y = 0;
    for (int i = 0; i < D; i++) {
        power /= 2;
        switch (ID[i]) {
            case '1':
                orig_X += power;
                orig_Y += power;
                break;
            case '2':
                orig_Y += power;
                break;
            case '3':
                break;
            case '4':
                orig_X += power;
                break;
        }
    }
    power = (1LL << D);
    long long new_X = orig_X + X;
    long long new_Y = orig_Y + Y;
    if (new_X < 0 || new_X >= power || new_Y < 0 || new_Y >= power) {
        cout << "-1\n";
    } else {
        cout << solve(new_X, new_Y, power) << "\n";
    }
    return 0;
}
