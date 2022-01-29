#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> cache(101, vector<int>(101, -1));

int solve(int a_rem, int z_rem, string& prefix) {
    if (a_rem < 0 || z_rem < 0) {
        return 0;
    }
    if (a_rem == 0 && z_rem == 0) {
        K--;
        if (K == 0) {
            cout << prefix << "\n";
            exit(0);
        }
        return 1;
    }
    int& ans = cache[a_rem][z_rem];
    if (ans >= 0 && ans < K) {
        K -= ans;
        return ans;
    }
    prefix.push_back('a');
    ans = solve(a_rem - 1, z_rem, prefix);
    prefix.pop_back();
    prefix.push_back('z');
    ans += solve(a_rem, z_rem - 1, prefix);
    prefix.pop_back();
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    string prefix;
    solve(N, M, prefix);
    cout << "-1\n";
    return 0;
}
