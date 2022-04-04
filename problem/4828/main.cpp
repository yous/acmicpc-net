#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

inline bool check_hex(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f');
}

inline bool check_tag(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string doc;
    while (getline(cin, doc)) {
        stack<string> contexts;
        bool is_escaped = false;
        bool is_tag = false;
        bool invalid = false;
        int idx = 0;
        int sz = doc.size();
        while (idx < sz) {
            char ch = doc[idx];
            if (is_escaped) {
                if (ch == 'l' || ch == 'g') {
                    if (idx + 2 < sz && doc[idx + 1] == 't' && doc[idx + 2] == ';') {
                        idx += 3;
                        is_escaped = false;
                        continue;
                    } else {
                        invalid = true;
                        break;
                    }
                } else if (ch == 'a') {
                    if (idx + 3 < sz && doc[idx + 1] == 'm' && doc[idx + 2] == 'p' && doc[idx + 3] == ';') {
                        idx += 4;
                        is_escaped = false;
                        continue;
                    } else {
                        invalid = true;
                        break;
                    }
                } else if (ch == 'x') {
                    if (idx + 2 < sz && check_hex(doc[idx + 1]) && check_hex(doc[idx + 2])) {
                        int nxt_idx = idx + 3;
                        while (nxt_idx + 1 < sz && check_hex(doc[nxt_idx]) && check_hex(doc[nxt_idx + 1])) {
                            nxt_idx += 2;
                        }
                        if (nxt_idx < sz && doc[nxt_idx] == ';') {
                            idx = nxt_idx + 1;
                            is_escaped = false;
                            continue;
                        } else {
                            invalid = true;
                            break;
                        }
                    } else {
                        invalid = true;
                        break;
                    }
                } else {
                    invalid = true;
                    break;
                }
            } else if (is_tag) {
                int tag_st = idx;
                bool is_open = true;
                if (ch == '/') {
                    is_open = false;
                    tag_st++;
                }
                int nxt_idx = tag_st;
                while (nxt_idx < sz && check_tag(doc[nxt_idx])) {
                    nxt_idx++;
                }
                if (nxt_idx == tag_st || nxt_idx >= sz) {
                    invalid = true;
                    break;
                }
                if (doc[nxt_idx] == '/') {
                    if (nxt_idx + 1 < sz && doc[nxt_idx + 1] == '>') {
                        idx = nxt_idx + 2;
                        is_tag = false;
                        continue;
                    } else {
                        invalid = true;
                        break;
                    }
                } else if (doc[nxt_idx] == '>') {
                    string tag = doc.substr(tag_st, nxt_idx - tag_st);
                    if (is_open) {
                        contexts.emplace(tag);
                        idx = nxt_idx + 1;
                        is_tag = false;
                        continue;
                    } else {
                        if (contexts.empty()) {
                            invalid = true;
                            break;
                        }
                        if (contexts.top() == tag) {
                            contexts.pop();
                            idx = nxt_idx + 1;
                            is_tag = false;
                            continue;
                        } else {
                            invalid = true;
                            break;
                        }
                    }
                } else {
                    invalid = true;
                    break;
                }
            }
            if (ch == '&') {
                is_escaped = true;
            } else if (ch == '<') {
                is_tag = true;
            } else if (ch == '>') {
                invalid = true;
                break;
            }
            idx++;
        }
        if (!invalid && contexts.empty()) {
            cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
    }
    return 0;
}
