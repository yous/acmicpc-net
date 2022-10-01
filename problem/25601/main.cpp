#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    map<string, int> classes;
    vector<int> parents(N, -1);
    int class_idx = 0;
    for (int i = 0; i < N - 1; i++) {
        string A, B;
        cin >> A >> B;
        int A_idx, B_idx;
        auto it = classes.find(A);
        if (it != classes.end()) {
            A_idx = it->second;
        } else {
            A_idx = classes[A] = class_idx++;
        }
        it = classes.find(B);
        if (it != classes.end()) {
            B_idx = it->second;
        } else {
            B_idx = classes[B] = class_idx++;
        }
        parents[A_idx] = B_idx;
    }
    string A, B;
    cin >> A >> B;
    int A_idx = classes.find(A)->second;
    int B_idx = classes.find(B)->second;
    int cur_idx = A_idx;
    while (parents[cur_idx] != -1) {
        if (parents[cur_idx] == B_idx) {
            cout << "1\n";
            return 0;
        }
        cur_idx = parents[cur_idx];
    }
    cur_idx = B_idx;
    while (parents[cur_idx] != -1) {
        if (parents[cur_idx] == A_idx) {
            cout << "1\n";
            return 0;
        }
        cur_idx = parents[cur_idx];
    }
    cout << "0\n";
    return 0;
}
