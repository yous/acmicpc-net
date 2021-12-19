#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9;

struct BigNum {
    vector<int> nums;

    BigNum operator+(BigNum& rhs) {
        BigNum res;
        auto it = nums.begin();
        auto oit = rhs.nums.begin();
        int up = 0;
        while (it != nums.end() && oit != rhs.nums.end()) {
            int add = *it + *oit + up;
            res.nums.emplace_back(add % MOD);
            up = add / MOD;
            it++;
            oit++;
        }
        while (it != nums.end()) {
            int add = *it + up;
            res.nums.emplace_back(add % MOD);
            up = add / MOD;
            it++;
        }
        while (oit != rhs.nums.end()) {
            int add = *oit + up;
            res.nums.emplace_back(add % MOD);
            up = add / MOD;
            oit++;
        }
        if (up > 0) {
            res.nums.emplace_back(up);
        }
        return res;
    }
};

ostream& operator<<(ostream& o, const BigNum& num) {
    int sz = num.nums.size();
    o << num.nums[sz - 1];
    for (int i = sz - 2; i >= 0; i--) {
        o << setfill('0') << setw(9) << num.nums[i];
    }
    return o;
}

string S;
int sz;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    sz = S.size();
    BigNum ans;
    ans.nums.emplace_back(1);
    BigNum cnt;
    cnt.nums.emplace_back(1);
    for (int idx = 0; idx < sz; idx++) {
        switch (S[idx]) {
            case 'L':
                ans = ans + ans;
                break;
            case 'R':
                ans = ans + ans + cnt;
                break;
            case 'P':
                break;
            case '*':
                ans = ans + ans + ans + ans + ans + cnt;
                cnt = cnt + cnt + cnt;
                break;
        }
    }
    cout << ans << "\n";
    return 0;
}
