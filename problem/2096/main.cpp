#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<short> matrix;

int solve_max(void) {
    int sel_a = matrix[0] / 100,
        sel_b = matrix[0] / 10 % 10,
        sel_c = matrix[0] % 10;
    for (int i = 1; i < N; i++) {
        int a = matrix[i] / 100,
            b = matrix[i] / 10 % 10,
            c = matrix[i] % 10;
        int next_sel_a = a + max(sel_a, sel_b),
            next_sel_b = b + max({sel_a, sel_b, sel_c}),
            next_sel_c = c + max(sel_b, sel_c);
        sel_a = next_sel_a;
        sel_b = next_sel_b;
        sel_c = next_sel_c;
    }
    return max({sel_a, sel_b, sel_c});
}

int solve_min(void) {
    int sel_a = matrix[0] / 100,
        sel_b = matrix[0] / 10 % 10,
        sel_c = matrix[0] % 10;
    for (int i = 1; i < N; i++) {
        int a = matrix[i] / 100,
            b = matrix[i] / 10 % 10,
            c = matrix[i] % 10;
        int next_sel_a = a + min(sel_a, sel_b),
            next_sel_b = b + min({sel_a, sel_b, sel_c}),
            next_sel_c = c + min(sel_b, sel_c);
        sel_a = next_sel_a;
        sel_b = next_sel_b;
        sel_c = next_sel_c;
    }
    return min({sel_a, sel_b, sel_c});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    matrix.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[i] = a * 100 + b * 10 + c;
    }
    cout << solve_max() << " " << solve_min() << "\n";
    return 0;
}
