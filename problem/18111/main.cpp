#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, B;
short field[501][501];

int elapsed(short ground) {
    int time = 0;
    int popped = 0;
    int pushed = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            short& num = field[i][j];
            if (num > ground) {
                time += (num - ground) * 2;
                popped += num - ground;
            } else {
                time += ground - num;
                pushed += ground - num;
            }
        }
    }
    if (popped + B < pushed) {
        return -1;
    }
    return time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> B;
    short max = 0;
    short min = 256;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            short& num = field[i][j];
            cin >> num;
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
    }
    int time = 987654321;
    short ans = 0;
    for (short ground = min; ground <= max; ground++) {
        int tmp = elapsed(ground);
        if (tmp == -1) {
            break;
        }
        if (tmp <= time) {
            time = tmp;
            ans = ground;
        }
    }
    cout << time << " " << ans << "\n";
    return 0;
}
