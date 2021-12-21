#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long A, B;
    cin >> A >> B;
    A--;
    long long ans = 0;
    long long diff = 1;
    long long div = 1;
    while (div <= B) {
        ans += (B / div - A / div) * diff;
        diff = div;
        div *= 2;
    }
    cout << ans << "\n";
    return 0;
}
