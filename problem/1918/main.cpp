#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string S;

string parse(string& s, int idx, int len) {
    stack<string> st;
    char prev_op = '\0';
    for (int i = idx; i < idx + len; i++) {
        if (s[i] == '(') {
            int j = i;
            int bracket = 1;
            while (bracket > 0) {
                j++;
                if (s[j] == '(') {
                    bracket++;
                } else if (s[j] == ')') {
                    bracket--;
                }
            }
            st.push(parse(s, i + 1, j - i - 1));
            i = j;
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            prev_op = s[i];
            st.push(string(1, s[i]));
            continue;
        } else {
            st.push(string(1, s[i]));
        }
        if (prev_op == '*' || prev_op == '/') {
            string operand2 = st.top();
            st.pop();
            char op = prev_op;
            st.pop();
            string operand = st.top();
            st.pop();
            prev_op = '\0';
            st.push(operand + operand2 + op);
        }
    }
    stack<string> tmp;
    while (!st.empty()) {
        tmp.push(st.top());
        st.pop();
    }
    string res;
    if (!tmp.empty()) {
        res += tmp.top();
        tmp.pop();
    }
    while (!tmp.empty()) {
        char op = tmp.top()[0];
        tmp.pop();
        string operand2 = tmp.top();
        tmp.pop();
        res += operand2 + op;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    cout << parse(S, 0, S.size()) << "\n";
    return 0;
}
