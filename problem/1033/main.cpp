#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int N;
int mass[10];

struct DisjointSet {
    vector<int> group;

    DisjointSet(int n) : group(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        if (group[n] == n) {
            return n;
        }
        return group[n] = find(group[n]);
    }

    void merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
        }
    }

    void mul_group(int g, int mul) {
        for (int i = 0; i < N; i++) {
            if (find(i) == g) {
                mass[i] *= mul;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    DisjointSet ds(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        int g = gcd(p, q);
        p /= g;
        q /= g;
        if (mass[a] == 0 && mass[b] == 0) {
            mass[a] = p;
            mass[b] = q;
        } else if (mass[a] == 0 || mass[b] == 0) {
            if (mass[b] == 0) {
                swap(a, b);
                swap(p, q);
            }
            if (mass[b] % q != 0) {
                int mul = q / gcd(mass[b], q);
                ds.mul_group(ds.find(b), mul);
            }
            mass[a] = mass[b] / q * p;
        } else {
            int ga = ds.find(a);
            int gb = ds.find(b);
            if (ga == gb) {
                continue;
            }
            long long l = lcm(1LL * mass[a] * q, 1LL * mass[b] * p);
            int mul_a = l / mass[a] / q;
            int mul_b = l / mass[b] / p;
            if (mul_a > 1) {
                ds.mul_group(ga, mul_a);
            }
            if (mul_b > 1) {
                ds.mul_group(gb, mul_b);
            }
        }
        ds.merge(a, b);
    }
    cout << mass[0];
    for (int i = 1; i < N; i++) {
        cout << " " << mass[i];
    }
    cout << "\n";
    return 0;
}
