#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<string> city(N);
    for (string& row : city) {
        cin >> row;
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (city[y][x] == '.') {
                city[y][x] = 'B';
            }
        }
    }
    for (int y = 0; y < N; y++) {
        int lo = 0;
        bool is_o = false;
        for (int x = 0; x < N; x++) {
            if (city[y][x] == 'X') {
                if (is_o) {
                    for (int i = lo; i < x; i++) {
                        city[y][i] = '.';
                    }
                }
                lo = x + 1;
                is_o = false;
                continue;
            }
            if (city[y][x] == 'O') {
                for (int i = lo; i < x; i++) {
                    city[y][i] = '.';
                }
                lo = x + 1;
                is_o = true;
            }
        }
        if (lo < N && is_o) {
            for (int i = lo; i < N; i++) {
                city[y][i] = '.';
            }
        }
    }
    for (int x = 0; x < N; x++) {
        int lo = 0;
        bool is_o = false;
        for (int y = 0; y < N; y++) {
            if (city[y][x] == 'X') {
                if (is_o) {
                    for (int i = lo; i < y; i++) {
                        city[i][x] = '.';
                    }
                }
                lo = y + 1;
                is_o = false;
                continue;
            }
            if (city[y][x] == 'O') {
                for (int i = lo; i < y; i++) {
                    city[i][x] = '.';
                }
                lo = y + 1;
                is_o = true;
            }
        }
        if (lo < N && is_o) {
            for (int i = lo; i < N; i++) {
                city[i][x] = '.';
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << city[i] << "\n";
    }
    return 0;
}
