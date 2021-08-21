#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> nums;
int M;
vector<vector<bool>> is_palin;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    is_palin.resize(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    for (int c = 0; c < N - 1; c++) {
        int lo = c;
        int hi = c;
        is_palin[lo][hi] = true;
        lo--;
        hi++;
        while (lo >= 0 && hi < N && nums[lo] == nums[hi]) {
            is_palin[lo][hi] = true;
            lo--;
            hi++;
        }
        lo = c;
        hi = c + 1;
        while (lo >= 0 && hi < N && nums[lo] == nums[hi]) {
            is_palin[lo][hi] = true;
            lo--;
            hi++;
        }
    }
    is_palin[N - 1][N - 1] = true;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        if (is_palin[S - 1][E - 1]) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}
