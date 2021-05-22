#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<typename T, class Container=vector<T>, class Compare=less<typename Container::value_types>>
class custom_priority_queue : public priority_queue<T, Container, Compare> {
  public:
    bool remove(const T& value) {
        auto it = find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        } else {
            return false;
        }
    }
};

int N, L;
vector<int> nums;
custom_priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    int i;
    int num;
    for (i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
        pq.push(make_pair(num, i));
        if (i >= L) {
            pq.remove(make_pair(nums[i - L], i - L));
        }
        cout << pq.top().first;
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
