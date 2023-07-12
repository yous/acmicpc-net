#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int N, M;
vector<tuple<short, int, int>> E;

struct DisjointSet {
    vector<int> group;

    DisjointSet(int n) : group(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        int& g = group[n];
        if (n == g) {
            return n;
        }
        return g = find(g);
    }

    bool merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    DisjointSet ds = DisjointSet(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        short c;
        cin >> a >> b >> c;
        E.emplace_back(c, a - 1, b - 1);
    }
    sort(E.begin(), E.end());
    E.pop_back();
    int sum = 0;
    int cnt = 0;
    for (auto& e : E) {
        short c;
        int a, b;
        tie(c, a, b) = e;
        if (ds.merge(a, b)) {
            sum += c;
            cnt++;
            if (cnt == N - 2) {
                break;
            }
        }
    }
    cout << sum << "\n";
    return 0;
}
