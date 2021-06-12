#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int OFF = 500000;
int N;
vector<int> blocks;
vector<int> sum_from(51);
int cache[2][1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    memset(cache, -1, sizeof(cache));
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum += num;
        blocks.push_back(num);
    }
    int _sum = 0;
    sum_from[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        _sum += blocks[i];
        sum_from[i] = _sum;
    }
    if (blocks[0] <= sum / 2) {
        cache[0][OFF + blocks[0]] = blocks[0];
        cache[0][OFF - blocks[0]] = 0;
    }
    cache[0][OFF] = 0;
    for (int i = 1; i < N; i++) {
        auto& arr = cache[i % 2];
        auto& prev_arr = cache[(i + 1) % 2];
        int block = blocks[i];
        for (int diff = -sum_from[i]; diff <= sum_from[i]; diff++) {
            int& height = prev_arr[OFF + diff];
            if (height < 0) {
                continue;
            }
            if (height + block <= sum / 2 && abs(diff + block) <= sum_from[i + 1]) {
                auto& val = arr[OFF + diff + block];
                if (height + block > val) {
                    val = height + block;
                }
            }
            if (height - (diff - block) <= sum / 2 && abs(diff - block) <= sum_from[i + 1]) {
                auto& val = arr[OFF + diff - block];
                if (height > val) {
                    val = height;
                }
            }
            if (abs(diff) <= sum_from[i + 1]) {
                auto& val = arr[OFF + diff];
                if (height > val) {
                    val = height;
                }
            }
        }
    }
    int ans = cache[(N - 1) % 2][OFF];
    if (ans > 0) {
        cout << ans << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
