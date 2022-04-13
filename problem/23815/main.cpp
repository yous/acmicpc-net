#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline int select(int num, string& op) {
    int other = op[1] - '0';
    switch (op[0]) {
        case '+':
            return num + other;
        case '-':
            return num - other;
        case '*':
            return num * other;
        case '/':
            return num / other;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int no_ad = 1;
    int after_ad = 1;
    bool no_ad_survived = true;
    bool after_ad_survived = true;
    for (int i = 0; i < N; i++) {
        string op1, op2;
        cin >> op1 >> op2;
        if (no_ad_survived) {
            int no_ad_res1 = select(no_ad, op1);
            int no_ad_res2 = select(no_ad, op2);
            int after_ad_res1 = select(after_ad, op1);
            int after_ad_res2 = select(after_ad, op2);
            after_ad = max({no_ad, after_ad_res1, after_ad_res2});
            no_ad = max(no_ad_res1, no_ad_res2);
            if (no_ad <= 0) {
                no_ad_survived = false;
            }
            if (after_ad <= 0) {
                after_ad_survived = false;
            }
        } else if (after_ad_survived) {
            int after_ad_res1 = select(after_ad, op1);
            int after_ad_res2 = select(after_ad, op2);
            after_ad = max(after_ad_res1, after_ad_res2);
            if (after_ad <= 0) {
                after_ad_survived = false;
            }
        }
    }
    if (no_ad_survived) {
        cout << max(no_ad, after_ad) << "\n";
    } else if (after_ad_survived) {
        cout << after_ad << "\n";
    } else {
        cout << "ddong game\n";
    }
    return 0;
}
