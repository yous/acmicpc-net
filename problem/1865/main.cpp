#include <algorithm>
#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 987654321;
int TC;
int N, M, W;
int dist[500];
vector<tuple<int, int, int>> edges;
vector<tuple<int, int, int>> wormholes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> TC;
    while (TC-- > 0) {
        cin >> N >> M >> W;
        fill(dist, dist + N, INF);
        dist[0] = 0;
        edges.clear();
        wormholes.clear();
        for (int i = 0; i < M; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S - 1, E - 1, T});
        }
        for (int i = 0; i < W; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            wormholes.push_back({S - 1, E - 1, T});
        }
        int step;
        for (step = 0; step < N; step++) {
            bool reduced = false;
            for (auto& edge : edges) {
                int S, E, T;
                tie(S, E, T) = edge;
                int new_dist = dist[S] + T;
                if (new_dist < dist[E]) {
                    reduced = true;
                    dist[E] = new_dist;
                }
                new_dist = dist[E] + T;
                if (new_dist < dist[S]) {
                    reduced = true;
                    dist[S] = new_dist;
                }
            }
            for (auto& wormhole : wormholes) {
                int S, E, T;
                tie(S, E, T) = wormhole;
                int new_dist = dist[S] - T;
                if (new_dist < dist[E]) {
                    reduced = true;
                    dist[E] = new_dist;
                }
            }
            if (!reduced) {
                break;
            }
        }
        if (step == N) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
