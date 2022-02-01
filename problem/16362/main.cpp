#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S;
int sz;

int solve(int& idx) {
    int lhs = 0;
    if (S[idx] == '(') {
        idx++;
        if (idx >= sz) {
            return -2;
        }
        lhs = solve(idx);
        if (lhs == -2) {
            return lhs;
        }
        if (idx >= sz) {
            return -2;
        }
        if (S[idx] == ')') {
            idx++;
        } else {
            return -2;
        }
    } else if (S[idx] >= 'a' && S[idx] <= 'z') {
        idx++;
    } else {
        return -2;
    }
    int oper_cnt = 0;
    int rhs = 0;
    while (idx < sz) {
        if (S[idx] == ')') {
            if (oper_cnt != 1) {
                return -1;
            }
            if (lhs != 0) {
                return lhs;
            } else {
                return rhs;
            }
        }
        if (S[idx] == '+' || S[idx] == '-' || S[idx] == '*' || S[idx] == '/' || S[idx] == '%') {
            oper_cnt++;
            idx++;
            if (idx >= sz) {
                return -2;
            }
        } else {
            return -2;
        }
        if (S[idx] == '(') {
            idx++;
            if (idx >= sz) {
                return -2;
            }
            rhs = min(rhs, solve(idx));
            if (rhs == -2) {
                return rhs;
            }
            if (idx >= sz) {
                return -2;
            }
            if (S[idx] == ')') {
                idx++;
            } else {
                return -2;
            }
        } else if (S[idx] >= 'a' && S[idx] <= 'z') {
            idx++;
        } else {
            return -2;
        }
    }
    if (oper_cnt != 1) {
        return -1;
    }
    if (lhs != 0) {
        return lhs;
    } else {
        return rhs;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string tok;
    while (cin >> tok) {
        S.append(tok);
    }
    sz = S.size();
    int idx = 0;
    int ans = solve(idx);
    if (idx < sz || ans == -2) {
        cout << "error\n";
    } else if (ans == 0) {
        cout << "proper\n";
    } else {
        cout << "improper\n";
    }
    return 0;
}
