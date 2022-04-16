#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> cnt(20001);
    set<int> nums;
    int smaller = 0;
    int larger = 0;
    short mid;
    cin >> mid;
    mid += 10000;
    cnt[mid]++;
    auto it = nums.emplace(mid).first;
    cout << mid - 10000 << "\n";
    for (int i = 1; i < N; i++) {
        short num;
        cin >> num;
        num += 10000;
        cnt[num]++;
        nums.emplace(num);
        if (num < mid) {
            smaller++;
            if (smaller >= cnt[mid] + larger) {
                --it;
                larger += cnt[mid];
                mid = *it;
                smaller -= cnt[mid];
            }
        } else if (num > mid) {
            larger++;
            if (smaller + cnt[mid] < larger) {
                ++it;
                smaller += cnt[mid];
                mid = *it;
                larger -= cnt[mid];
            }
        }
        cout << mid - 10000 << "\n";
    }
    return 0;
}
