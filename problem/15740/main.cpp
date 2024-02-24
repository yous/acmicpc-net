#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class BigInt {
    vector<int> nums;
    int sign = 1;

    bool abs_lt(const BigInt& rhs) const {
        auto sz = nums.size();
        if (sz != rhs.nums.size()) {
            return sz < rhs.nums.size();
        }
        for (int i = sz - 1; i >= 0; i--) {
            if (nums[i] != rhs.nums[i]) {
                return nums[i] < rhs.nums[i];
            }
        }
        return false;
    }

    void normalize() {
        int carry = 0;
        auto sz = nums.size();
        for (int i = 0; i < sz; i++) {
            nums[i] += carry;
            if (nums[i] < 0) {
                carry = -1;
                nums[i] += 10;
            } else if (nums[i] >= 10) {
                carry = nums[i] / 10;
                nums[i] %= 10;
            } else {
                carry = 0;
            }
        }
        if (carry > 0) {
            nums.emplace_back(carry);
        }
        while (nums.size() > 1 && nums.back() == 0) {
            nums.pop_back();
        }
        if (nums.size() == 1 && nums[0] == 0 && sign == -1) {
            sign = 1;
        }
    }

  public:
    BigInt() {
        nums.resize(1);
    }

    BigInt(const string& s) : nums(s.size()) {
        auto sz = s.size();
        for (int i = 0; i < sz; i++) {
            nums[sz - i - 1] = s[i] - '0';
        }
        if (s[0] == '-') {
            sign = -1;
            nums.pop_back();
        }
    }

    BigInt operator *(const BigInt& rhs) const {
        BigInt res;
        auto sz = nums.size();
        auto rsz = rhs.nums.size();
        res.nums.resize(sz + rsz);
        res.sign = (sign == rhs.sign) ? 1 : -1;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < rsz; j++) {
                res.nums[i + j] += nums[i] * rhs.nums[j];
            }
        }
        res.normalize();
        return res;
    }

    BigInt operator +(const BigInt& rhs) const {
        BigInt res;
        const BigInt* adder;
        if (abs_lt(rhs)) {
            res = rhs;
            adder = this;
        } else {
            res = *this;
            adder = &rhs;
        }
        auto sz = adder->nums.size();
        for (int i = 0; i < sz; i++) {
            if (res.sign == adder->sign) {
                res.nums[i] = res.nums[i] + adder->nums[i];
            } else {
                res.nums[i] = res.nums[i] - adder->nums[i];
            }
        }
        res.normalize();
        return res;
    }

    BigInt operator -(const BigInt& rhs) const {
        BigInt neg = rhs;
        neg.sign = rhs.sign * -1;
        return *this + neg;
    }

    string to_string() {
        string res;
        if (sign == -1) {
            res += '-';
        }
        auto sz = nums.size();
        for (int i = sz - 1; i >= 0; i--) {
            res += nums[i] + '0';
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string A, B;
    cin >> A >> B;
    BigInt A_bi(A);
    BigInt B_bi(B);
    cout << (A_bi + B_bi).to_string() << "\n";
    return 0;
}
