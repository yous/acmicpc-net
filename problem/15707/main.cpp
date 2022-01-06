#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    long long r;
    cin >> a >> b >> r;
    if (a == "0" || b == "0") {
        cout << "0\n";
        return 0;
    }
    if (a.size() >= 20 || b.size() >= 20) {
        cout << "overflow\n";
        return 0;
    }
    if ((a.size() == 19 && a >= to_string(1ULL << 63)) ||
            (b.size() == 19 && b >= to_string(1ULL << 63))) {
        cout << "overflow\n";
        return 0;
    }
    long long a_num = stoll(a);
    long long b_num = stoll(b);
    if (r / a_num < b_num) {
        cout << "overflow\n";
    } else {
        cout << a_num * b_num << "\n";
    }
    return 0;
}
