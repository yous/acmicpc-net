#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = static_cast<int>(1e9) + 2;
int N;
vector<tuple<bool, int, int, int>> cows;
vector<int> grasses;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    grasses.resize(N);
    for (int i = 0; i < N; i++) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;
        cows.emplace_back(dir == 'N', x, y, i);
    }
    sort(cows.begin(), cows.end(), [](const auto& lhs, const auto& rhs) {
        return get<1>(lhs) + get<2>(lhs) < get<1>(rhs) + get<2>(rhs);
    });
    for (int i = N - 1; i >= 0; i--) {
        auto [north, x, y, idx] = cows[i];
        int grass = INF;
        for (int j = i + 1; j < N; j++) {
            auto [onorth, ox, oy, oidx] = cows[j];
            if (north == onorth) {
                if (north && x == ox) {
                    grass = min(grass, oy - y);
                } else if (!north && y == oy) {
                    grass = min(grass, ox - x);
                }
                continue;
            }
            if (x + y == ox + oy) {
                continue;
            }
            if (north && ox <= x && grasses[oidx] >= x - ox) {
                grass = min(grass, oy - y);
            } else if (!north && oy <= y && grasses[oidx] >= y - oy) {
                grass = min(grass, ox - x);
            }
        }
        grasses[idx] = grass;
    }
    for (int i = 0; i < N; i++) {
        int grass = grasses[i];
        if (grass == INF) {
            cout << "Infinity\n";
        } else {
            cout << grass << "\n";
        }
    }
    return 0;
}
