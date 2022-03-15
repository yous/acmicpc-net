#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 1);
    cout << (dist(gen) == 0 ? "Yonsei\n" : "Korea\n");
    return 0;
}
