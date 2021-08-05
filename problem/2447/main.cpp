#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const vector<string> unit = {"***", "* *", "***", "   "};
int N;

vector<vector<bool>> generate(int n) {
    if (n == 1) {
        return {{true}};
    }
    vector<vector<bool>> child = generate(n / 3);
    int child_sz = child.size();
    vector<vector<bool>> ans(n);
    for (int i = 0; i < child_sz; i++) {
        for (int j = 0; j < 3; j++) {
            ans[i].insert(ans[i].end(), child[i].begin(), child[i].end());
        }
    }
    int offset = child_sz;
    for (int i = 0; i < child_sz; i++) {
        ans[offset + i].insert(ans[offset + i].end(), child[i].begin(), child[i].end());
        ans[offset + i].insert(ans[offset + i].end(), child_sz, false);
        ans[offset + i].insert(ans[offset + i].end(), child[i].begin(), child[i].end());
    }
    offset += child_sz;
    for (int i = 0; i < child_sz; i++) {
        ans[offset + i].insert(ans[offset + i].end(), ans[i].begin(), ans[i].end());
    }
    return ans;
}

void print(vector<bool>& row) {
    for (int i = 0; i < 3; i++) {
        for (auto p : row) {
            if (p) {
                cout << unit[i];
            } else {
                cout << unit[3];
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<vector<bool>> matrix = generate(N / 3);
    for (auto& row : matrix) {
        print(row);
    }
    return 0;
}
