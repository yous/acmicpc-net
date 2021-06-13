#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<int> prices;

struct DisjointSet {
    vector<int> group;
    vector<int> price;

    DisjointSet(int n, vector<int>& prices) : group(n), price(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
            price[i] = prices[i];
        }
    }

    int find(int n) {
        if (n == group[n]) {
            return n;
        }
        return group[n] = find(group[n]);
    }

    int merge(int p, int q) {
        p = find(p);
        q = find(q);
        if (p != q) {
            int p_price = price[p];
            int q_price = price[q];
            if (p_price < q_price) {
                group[q] = p;
                return q_price;
            } else {
                group[p] = q;
                return p_price;
            }
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        prices.push_back(num);
        sum += num;
    }
    DisjointSet ds = DisjointSet(N, prices);
    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        sum -= ds.merge(v - 1, w - 1);
    }
    if (K >= sum) {
        cout << sum << "\n";
    } else {
        cout << "Oh no\n";
    }
    return 0;
}
