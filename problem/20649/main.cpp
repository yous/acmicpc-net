#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = static_cast<int>(1e9) + 2;
int N;
vector<tuple<bool, int, int, int>> cows;
vector<int> grasses;
vector<int> stopped_by;
vector<int> stopped;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    grasses.resize(N);
    stopped_by.resize(N, -1);
    stopped.resize(N);
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
        int stop_by = -1;
        for (int j = i + 1; j < N; j++) {
            auto [onorth, ox, oy, oidx] = cows[j];
            if (north == onorth) {
                if (north && x == ox) {
                    if (oy - y < grass) {
                        grass = oy - y;
                        stop_by = oidx;
                    }
                } else if (!north && y == oy) {
                    if (ox - x < grass) {
                        grass = ox - x;
                        stop_by = oidx;
                    }
                }
                continue;
            }
            if (x + y == ox + oy) {
                continue;
            }
            if (north && ox <= x && grasses[oidx] >= x - ox) {
                if (oy - y < grass) {
                    grass = oy - y;
                    stop_by = oidx;
                }
            } else if (!north && oy <= y && grasses[oidx] >= y - oy) {
                if (ox - x < grass) {
                    grass = ox - x;
                    stop_by = oidx;
                }
            }
        }
        grasses[idx] = grass;
        stopped_by[idx] = stop_by;
        while (stop_by != -1) {
            stopped[stop_by]++;
            stop_by = stopped_by[stop_by];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << stopped[i] << "\n";
    }
    return 0;
}
