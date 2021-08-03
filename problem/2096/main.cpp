#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int a, b, c;
    cin >> a >> b >> c;
    int max_a = a,
        max_b = b,
        max_c = c;
    int min_a = a,
        min_b = b,
        min_c = c;
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;
        int next_max_a = a + max(max_a, max_b),
            next_max_b = b + max({max_a, max_b, max_c}),
            next_max_c = c + max(max_b, max_c);
        int next_min_a = a + min(min_a, min_b),
            next_min_b = b + min({min_a, min_b, min_c}),
            next_min_c = c + min(min_b, min_c);
        max_a = next_max_a;
        max_b = next_max_b;
        max_c = next_max_c;
        min_a = next_min_a;
        min_b = next_min_b;
        min_c = next_min_c;
    }
    cout << max({max_a, max_b, max_c}) << " " << min({min_a, min_b, min_c}) << "\n";
    return 0;
}
