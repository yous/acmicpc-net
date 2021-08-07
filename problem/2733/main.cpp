#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

const int TAPE_SIZE = 32768;
int T;
string program;
vector<unsigned char> tape(TAPE_SIZE);

void run(map<int, int>& brackets) {
    int pos = 0;
    int ptr = 0;
    int sz = program.size();
    while (pos < sz) {
        char ch = program[pos];
        switch (ch) {
            case '>':
                ptr = (ptr + 1) % TAPE_SIZE;
                break;
            case '<':
                ptr = (ptr - 1 + TAPE_SIZE) % TAPE_SIZE;
                break;
            case '+':
                tape[ptr] = (tape[ptr] + 1) % 256;
                break;
            case '-':
                tape[ptr] = (tape[ptr] - 1 + 256) % 256;
                break;
            case '.':
                cout << tape[ptr];
                break;
            case '[':
                if (tape[ptr] == 0) {
                    pos = brackets[pos];
                }
                break;
            case ']':
                if (tape[ptr] != 0) {
                    pos = brackets[pos];
                }
                break;
        }
        pos++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "PROGRAM #" << t << ":\n";
        program.clear();
        fill(tape.begin(), tape.end(), 0);
        map<int, int> brackets;
        stack<int> st;
        bool compile_error = false;
        while (true) {
            string row;
            getline(cin, row);
            if (row == "end") {
                break;
            }
            if (compile_error) {
                continue;
            }
            for (int i = 0; i < row.size(); i++) {
                if (row[i] == '%') {
                    break;
                }
                switch (row[i]) {
                    case '>':
                    case '<':
                    case '+':
                    case '-':
                    case '.':
                        program += row[i];
                        break;
                    case '[':
                        st.push(program.size());
                        program += row[i];
                        break;
                    case ']':
                        if (st.empty()) {
                            compile_error = true;
                        } else {
                            int idx = st.top();
                            st.pop();
                            int sz = program.size();
                            brackets[idx] = sz;
                            brackets[sz] = idx;
                            program += row[i];
                        }
                        break;
                }
                if (compile_error) {
                    break;
                }
            }
        }
        if (!st.empty()) {
            compile_error = true;
        }
        if (compile_error) {
            cout << "COMPILE ERROR\n";
            continue;
        }
        run(brackets);
        cout << "\n";
    }
    return 0;
}
