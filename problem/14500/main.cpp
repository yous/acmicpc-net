#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<short>> paper;

struct Tetromino {
    short height;
    short width;
    vector<pair<short, short>> points;

    Tetromino(short h, short w, vector<pair<short, short>> p) : height(h), width(w), points(p) {}
};

Tetromino tetros[] = {
    Tetromino(1, 4, {{0, 0}, {0, 1}, {0, 2}, {0, 3}}),
    Tetromino(2, 2, {{0, 0}, {0, 1}, {1, 0}, {1, 1}}),
    Tetromino(2, 3, {{0, 0}, {0, 1}, {0, 2}, {1, 0}}),
    Tetromino(2, 3, {{0, 0}, {0, 1}, {0, 2}, {1, 1}}),
    Tetromino(2, 3, {{0, 0}, {0, 1}, {0, 2}, {1, 2}}),
    Tetromino(2, 3, {{0, 0}, {0, 1}, {1, 1}, {1, 2}}),
    Tetromino(2, 3, {{0, 0}, {1, 0}, {1, 1}, {1, 2}}),
    Tetromino(2, 3, {{0, 1}, {0, 2}, {1, 0}, {1, 1}}),
    Tetromino(2, 3, {{0, 1}, {1, 0}, {1, 1}, {1, 2}}),
    Tetromino(2, 3, {{0, 2}, {1, 0}, {1, 1}, {1, 2}}),
    Tetromino(3, 2, {{0, 0}, {0, 1}, {1, 0}, {2, 0}}),
    Tetromino(3, 2, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}),
    Tetromino(3, 2, {{0, 0}, {1, 0}, {1, 1}, {2, 0}}),
    Tetromino(3, 2, {{0, 0}, {1, 0}, {1, 1}, {2, 1}}),
    Tetromino(3, 2, {{0, 0}, {1, 0}, {2, 0}, {2, 1}}),
    Tetromino(3, 2, {{0, 1}, {1, 0}, {1, 1}, {2, 0}}),
    Tetromino(3, 2, {{0, 1}, {1, 0}, {1, 1}, {2, 1}}),
    Tetromino(3, 2, {{0, 1}, {1, 1}, {2, 0}, {2, 1}}),
    Tetromino(4, 1, {{0, 0}, {1, 0}, {2, 0}, {3, 0}})
};

int max_tetro(Tetromino& tetro) {
    int ans = 0;
    for (int i = 0; i < N - tetro.height + 1; i++) {
        for (int j = 0; j < M - tetro.width + 1; j++) {
            int sum = 0;
            for (auto& p : tetro.points) {
                int y = p.first,
                    x = p.second;
                sum += paper[i + y][j + x];
            }
            ans = max(ans, sum);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    paper.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            short num;
            cin >> num;
            paper[i].push_back(num);
        }
    }
    int ans = 0;
    for (auto& tetro : tetros) {
        ans = max(ans, max_tetro(tetro));
    }
    cout << ans << "\n";
    return 0;
}
