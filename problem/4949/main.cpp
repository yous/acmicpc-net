#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool balanced(string& s) {
    stack<char> st;
    for (char ch : s) {
        switch(ch) {
            case '(':
            case '[':
                st.push(ch);
                break;
            case ')':
                if (st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
                break;
        }
    }
    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (getline(cin, s)) {
        if (s == ".") {
            break;
        }
        if (balanced(s)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
