#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const string stars[] = {"  *   ", " * *  ", "***** "};
const string spaces = "      ";
int N;

vector<vector<bool>> generate(int n) {
    if (n == 1) {
        return vector<vector<bool>>{{true}};
    }
    vector<vector<bool>> child = generate(n / 2);
    int sz = child.size();
    for (int i = 0; i < sz; i++) {
        vector<bool> row;
        row.insert(row.end(), child[i].begin(), child[i].end());
        for (int j = 0; j < sz - i - 1; j++) {
            row.push_back(false);
        }
        row.insert(row.end(), child[i].begin(), child[i].end());
        child.push_back(row);
    }
    return child;
}

void print(vector<bool>& row, int offset) {
    for (int i = 0; i < 3; i++) {
        cout << string(offset, ' ');
        for (int p : row) {
            if (p) {
                cout << stars[i];
            } else {
                cout << spaces;
            }
        }
        cout << string(offset, ' ') << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<vector<bool>> triangle = generate(N / 3);
    for (int i = 0; i < N / 3; i++) {
        print(triangle[i], N - (i + 1) * 3);
    }
    return 0;
}
