#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    map<string, int> extensions;
    for (int i = 0; i < N; i++) {
        string filename;
        cin >> filename;
        auto pos = filename.find(".");
        extensions[filename.substr(pos + 1, filename.size() - pos - 1)]++;
    }
    for (auto it = extensions.begin(); it != extensions.end(); ++it) {
        cout << it->first << " " << it->second << "\n";
    }
    return 0;
}
