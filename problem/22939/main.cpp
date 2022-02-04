#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int dist(pair<int, int>& lhs, pair<int, int>& rhs) {
    return abs(rhs.first - lhs.first) + abs(rhs.second - lhs.second);
}

int solve(vector<string>& field, char topping) {
    vector<pair<int, int>> toppings;
    pair<int, int> home, crew;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (field[y][x] == 'H') {
                home = {y, x};
            } else if (field[y][x] == '#') {
                crew = {y, x};
            } else if (field[y][x] == topping) {
                toppings.emplace_back(y, x);
            }
        }
    }
    int dh1 = dist(home, toppings[0]);
    int dh2 = dist(home, toppings[1]);
    int dh3 = dist(home, toppings[2]);
    int d12 = dist(toppings[0], toppings[1]);
    int d13 = dist(toppings[0], toppings[2]);
    int d23 = dist(toppings[1], toppings[2]);
    int d21 = d12, d31 = d13, d32 = d23;
    int d1c = dist(toppings[0], crew);
    int d2c = dist(toppings[1], crew);
    int d3c = dist(toppings[2], crew);
    return min({dh1 + d12 + d23 + d3c,
               dh1 + d13 + d32 + d2c,
               dh2 + d21 + d13 + d3c,
               dh2 + d23 + d31 + d1c,
               dh3 + d31 + d12 + d2c,
               dh3 + d32 + d21 + d1c});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<string> field(N);
    for (auto& row : field) {
        cin >> row;
    }
    string toppings = "JCBW";
    int min_time = 1e9;
    char ans = 'J';
    for (char topping : toppings) {
        int res = solve(field, topping);
        if (min_time > res) {
            min_time = res;
            ans = topping;
        }
    }
    switch (ans) {
        case 'J':
            cout << "Assassin\n";
            break;
        case 'C':
            cout << "Healer\n";
            break;
        case 'B':
            cout << "Mage\n";
            break;
        case 'W':
            cout << "Tanker\n";
            break;
    }
    return 0;
}
