#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string msg("WelcomeToSMUPC");
    cout << msg[(N - 1) % msg.size()] << "\n";
    return 0;
}
