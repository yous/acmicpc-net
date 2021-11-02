#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string formula;
int sz;

int max_depth(void) {
    int res = 0;
    int depth = 0;
    for (int i = 0; i < sz; i++) {
        if (formula[i] == '(') {
            depth++;
            res = max(res, depth);
        } else if (formula[i] == ')') {
            depth--;
        }
    }
    return res;
}

pair<int, bool> solve(int lo, bool is_and) {
    bool res = is_and ? true : false;
    lo++;
    while (formula[lo] != ')') {
        if (formula[lo] != '(') {
            res = is_and ? (res && formula[lo] == 'T') : (res || formula[lo] == 'T');
            lo++;
        } else {
            auto [next_lo, child_res] = solve(lo, !is_and);
            res = is_and ? (res && child_res) : (res || child_res);
            lo = next_lo;
        }
    }
    return make_pair(lo + 1, res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (cin >> formula) {
        sz = formula.size();
        if (sz == 2) {
            break;
        }
        int depth = max_depth();
        cout << t << ". " << (solve(0, depth % 2 == 1).second ? "true" : "false") << "\n";
        t++;
    }
    return 0;
}
