#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, M;
map<string, int> poket_to_num;
vector<string> pokets;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    string poket;
    int num;
    pokets.push_back("");
    for (int i = 1; i <= N; i++) {
        cin >> poket;
        pokets.push_back(poket);
        poket_to_num.insert(make_pair(poket, i));
    }
    for (int i = 0; i < M; i++) {
        cin >> poket;
        if ('0' <= poket[0] && poket[0] <= '9') {
            num = stoi(poket);
            cout << pokets[num] << "\n";
        } else {
            cout << poket_to_num[poket] << "\n";
        }
    }
    return 0;
}
