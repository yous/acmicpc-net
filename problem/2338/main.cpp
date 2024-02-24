#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int ELEM_SIZE = 8;
const int MOD = 1e8;

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

    BigInt(const string& s) {
        int start = 0;
        if (s[0] == '-') {
            sign = -1;
            start++;
        }
        auto sz = s.size();
        int cnt = (sz - start + ELEM_SIZE - 1) / ELEM_SIZE;
        nums.resize(cnt);
        int idx = 0;
        for (int i = sz - 1; i >= start; i -= ELEM_SIZE) {
            int num = 0;
            for (int j = min(ELEM_SIZE - 1, i - start); j >= 0; j--) {
                num = num * 10 + s[i - j] - '0';
            }
            nums[idx++] = num;
        }
        normalize();
    }

    BigInt operator *(const BigInt& rhs) const {
        BigInt res;
        auto sz = nums.size();
        auto rsz = rhs.nums.size();
        res.nums.resize(sz + rsz);
        res.sign = (sign == rhs.sign) ? 1 : -1;
        int carry = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < rsz; j++) {
                long long mul = res.nums[i + j] + 1LL * nums[i] * rhs.nums[j] + carry;
                res.nums[i + j] = mul % MOD;
                carry = mul / MOD;
            }
            int offset = rsz;
            while (carry > 0) {
                int add = res.nums[i + offset] + carry;
                res.nums[i + offset] = add % MOD;
                carry = add / MOD;
                offset++;
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
        res.nums.resize(res.nums.size() + 1);
        auto sz = adder->nums.size();
        int carry = 0;
        for (int i = 0; i < sz; i++) {
            int add = (res.sign == adder->sign)
                ? res.nums[i] + adder->nums[i] + carry
                : res.nums[i] - adder->nums[i] + carry;
            if (add < 0) {
                res.nums[i] = add + MOD;
                carry = -1;
            } else {
                res.nums[i] = add % MOD;
                carry = add / MOD;
            }
        }
        int offset = sz;
        while (carry != 0) {
            int add = res.nums[offset] + carry;
            res.nums[offset] = add % MOD;
            carry = add / MOD;
            offset++;
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
        res += std::to_string(nums.back());
        for (int i = sz - 2; i >= 0; i--) {
            for (int j = MOD / 10; j >= 1; j /= 10) {
                res += nums[i] / j % 10 + '0';
            }
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
    cout << (A_bi - B_bi).to_string() << "\n";
    cout << (A_bi * B_bi).to_string() << "\n";
    return 0;
}
