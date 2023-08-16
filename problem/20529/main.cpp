#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int diff(int lhs, int rhs) {
    return (((lhs & 8) ^ (rhs & 8)) >> 3) +
        (((lhs & 4) ^ (rhs & 4)) >> 2) +
        (((lhs & 2) ^ (rhs & 2)) >> 1) +
        ((lhs & 1) ^ (rhs & 1));
}

int solve(int val, vector<int>& selected, vector<int>& mbti) {
    if (selected.size() == 3) {
        return diff(selected[0], selected[1]) +
            diff(selected[1], selected[2]) +
            diff(selected[2], selected[0]);
    }
    int ans = 12;
    for (int i = val; i < 16; i++) {
        if (mbti[i] == 0) {
            continue;
        }
        mbti[i]--;
        selected.emplace_back(i);
        ans = min(ans, solve(i, selected, mbti));
        selected.pop_back();
        mbti[i]++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        vector<int> mbti(16);
        for (int i = 0; i < N; i++) {
            char ei, sn, tf, jp;
            cin >> ei >> sn >> tf >> jp;
            int idx = (ei == 'I' ? 8 : 0) + (sn == 'N' ? 4 : 0) + (tf == 'F' ? 2 : 0) + (jp == 'P' ? 1 : 0);
            mbti[idx]++;
        }
        vector<int> selected;
        cout << solve(0, selected, mbti) << "\n";
    }
    return 0;
}
