#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> movies;

void gen(int digit, int num, int order) {
    if (digit == 0) {
        movies.push_back(num);
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (i != 0) {
            gen(digit - 1, i * order + num, order * 10);
        }
        gen(digit - 1, num * 10 + i, order * 10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    movies.push_back(666);
    for (int i = 1; i <= 4; i++) {
        gen(i, 666, 1000);
    }
    sort(movies.begin(), movies.end());
    movies.erase(unique(movies.begin(), movies.end()), movies.end());
    cout << movies[N - 1] << "\n";
    return 0;
}
