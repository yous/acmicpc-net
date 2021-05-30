#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int N;
vector<tuple<int, int, string>> people;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int age;
    int idx = 0;
    string name;
    while (N-- > 0) {
        cin >> age >> name;
        people.push_back({age, idx, name});
        idx++;
    }
    sort(people.begin(), people.end());
    for (auto person : people) {
        cout << get<0>(person) << " " << get<2>(person) << "\n";
    }
    return 0;
}
