#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> primes;
vector<vector<int>> order_primes;

bool is_prime(int num) {
    int _sqrt = sqrt(num);
    for (auto it = primes.begin(); it != primes.end() && *it <= _sqrt; it++) {
        if (num % *it == 0) {
            return false;
        }
    }
    return true;
}

void get_prime(int order) {
    int limit = 1;
    int i;
    for (i = 0; i < order; i++) {
        limit *= 10;
    }
    int num = 10;
    while (num < limit) {
        if (is_prime(num + 1)) {
            primes.push_back(num + 1);
        }
        if (is_prime(num + 3)) {
            primes.push_back(num + 3);
        }
        if (is_prime(num + 7)) {
            primes.push_back(num + 7);
        }
        if (is_prime(num + 9)) {
            primes.push_back(num + 9);
        }
        num += 10;
    }
}

void solve(int order) {
    if (order > N) {
        return;
    }
    vector<int> ops = order_primes.at(order - 2);
    vector<int> new_ops;
    for (auto it = ops.begin(); it != ops.end(); it++) {
        if (is_prime(*it * 10 + 1)) {
            new_ops.push_back(*it * 10 + 1);
        }
        if (is_prime(*it * 10 + 3)) {
            new_ops.push_back(*it * 10 + 3);
        }
        if (is_prime(*it * 10 + 7)) {
            new_ops.push_back(*it * 10 + 7);
        }
        if (is_prime(*it * 10 + 9)) {
            new_ops.push_back(*it * 10 + 9);
        }
    }
    order_primes.push_back(new_ops);
    solve(order + 1);
}

int main() {
    cin >> N;
    vector<int> first_primes;
    first_primes.push_back(2);
    first_primes.push_back(3);
    first_primes.push_back(5);
    first_primes.push_back(7);
    order_primes.push_back(first_primes);
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    if (N == 1) {
        vector<int> ops = order_primes.at(0);
        for (auto it = ops.begin(); it != ops.end(); it++) {
            cout << *it << "\n";
        }
    } else {
        get_prime((N + 1) / 2);
        solve(2);
        vector<int> ops = order_primes.at(N - 1);
        for (auto it = ops.begin(); it != ops.end(); it++) {
            cout << *it << "\n";
        }
    }
    return 0;
}
