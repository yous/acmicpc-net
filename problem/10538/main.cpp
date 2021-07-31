#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const vector<int> BASE = {211, 1187};
const int MOD = static_cast<int>(1e9) + 7;
int H_p, W_p, H_m, W_m;
vector<string> picture;
vector<string> masterpiece;
vector<vector<int>> P(BASE.size());

template<typename T>
struct Hash {
    const vector<int> base;
    vector<vector<int>> h;

    Hash(const T& s, const vector<int>& base) : base(base), h(base.size(), vector<int>(s.size())) {
        int sz = s.size();
        for (int i = 0; i < base.size(); i++) {
            h[i][0] = s[0];
            for (int j = 1; j < sz; j++) {
                h[i][j] = (1LL * h[i][j - 1] * base[i] + s[j]) % MOD;
            }
        }
    }

    vector<int> value(int a, int b) {
        vector<int> res;
        if (a == 0) {
            for (int i = 0; i < base.size(); i++) {
                res.push_back(h[i][b]);
            }
            return res;
        }
        for (int i = 0; i < base.size(); i++) {
            res.push_back((h[i][b] - 1LL * h[i][a - 1] * P[i][b - a + 1] % MOD + MOD) % MOD);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> H_p >> W_p >> H_m >> W_m;
    picture.resize(H_p);
    masterpiece.resize(H_m);
    for (int i = 0; i < BASE.size(); i++) {
        P[i].resize(max(H_m, W_m));
        P[i][0] = 1;
        for (int j = 1; j < P[i].size(); j++) {
            P[i][j] = 1LL * P[i][j - 1] * BASE[i] % MOD;
        }
    }
    for (auto& row : picture) {
        cin >> row;
    }
    for (auto& row : masterpiece) {
        cin >> row;
    }
    vector<Hash<string>> hash_pic;
    for (int i = 0; i < H_p; i++) {
        hash_pic.emplace_back(picture[i], vector<int>{BASE.begin(), BASE.begin() + 1});
    }
    vector<Hash<string>> hash_mast;
    for (int i = 0; i < H_m; i++) {
        hash_mast.emplace_back(masterpiece[i], vector<int>{BASE.begin(), BASE.begin() + 1});
    }
    vector<int> pic_hashvals;
    for (int i = 0; i < H_p; i++) {
        pic_hashvals.push_back(hash_pic[i].value(0, W_p - 1)[0]);
    }
    vector<int> pic_hashval = Hash<vector<int>>(pic_hashvals, BASE).value(0, H_p - 1);
    int ans = 0;
    for (int j = 0; j < W_m - W_p + 1; j++) {
        vector<int> line_hashvals;
        for (int i = 0; i < H_m; i++) {
            line_hashvals.push_back(hash_mast[i].value(j, j + W_p - 1)[0]);
        }
        Hash<vector<int>> cur_hash(line_hashvals, BASE);
        for (int i = 0; i < H_m - H_p + 1; i++) {
            if (cur_hash.value(i, i + H_p - 1) == pic_hashval) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
