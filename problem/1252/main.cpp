#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string num1, num2;
    cin >> num1 >> num2;
    auto sz1 = num1.size();
    auto sz2 = num2.size();
    int start = 0;
    while (start < sz1 - 1 && num1[start] == '0') {
        start++;
    }
    num1 = num1.substr(start, sz1 - start);
    sz1 -= start;
    start = 0;
    while (start < sz2 - 1 && num2[start] == '0') {
        start++;
    }
    num2 = num2.substr(start, sz2 - start);
    sz2 -= start;
    string res;
    int carry = 0;
    while (sz1 > 0 && sz2 > 0) {
        sz1--;
        sz2--;
        int sum = num1[sz1] - '0' + num2[sz2] - '0' + carry;
        res += '0' + sum % 2;
        carry = sum / 2;
    }
    if (sz2 > 0) {
        swap(sz1, sz2);
        swap(num1, num2);
    }
    while (sz1 > 0) {
        sz1--;
        int sum = num1[sz1] - '0' + carry;
        res += '0' + sum % 2;
        carry = sum / 2;
    }
    if (carry > 0) {
        res += '1';
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
    return 0;
}
