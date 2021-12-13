#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const char ALPHANUM[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
string S;
int idx, offset;

int get_bin(int count) {
    if (offset + count <= 4) {
        int chr = (S[idx] >= 'A' ? S[idx] - 'A' + 10 : S[idx] - '0');
        int res = (chr & ((1 << (4 - offset)) - 1)) >> (4 - offset - count);
        offset += count;
        if (offset == 4) {
            idx++;
            offset = 0;
        }
        return res;
    }
    int rem = 4 - offset;
    int res = get_bin(rem);
    return (res << (count - rem)) + get_bin(count - rem);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int P;
    cin >> P;
    while (P-- > 0) {
        cin >> S;
        int sz = S.size();
        idx = 0;
        offset = 0;
        bool term = false;
        int ans = 0;
        string decoded;
        while (idx < sz) {
            int mode = get_bin(4);
            int cnt;
            switch (mode) {
                case 0:
                    term = true;
                    break;
                case 1:
                    cnt = get_bin(10);
                    for (int i = 0; i < cnt / 3; i++) {
                        int num = get_bin(10);
                        if (num < 100) {
                            decoded += '0';
                            if (num < 10) {
                                decoded += '0';
                            }
                        }
                        decoded.append(to_string(num));
                    }
                    if (cnt % 3 != 0) {
                        int num = get_bin(1 + (cnt % 3) * 3);
                        if (cnt % 3 == 2 && num < 10) {
                            decoded += '0';
                        }
                        decoded.append(to_string(num));
                    }
                    ans += cnt;
                    break;
                case 2:
                    cnt = get_bin(9);
                    for (int i = 0; i < cnt / 2; i++) {
                        int alpha = get_bin(11);
                        decoded += ALPHANUM[alpha / 45];
                        decoded += ALPHANUM[alpha % 45];
                    }
                    if (cnt % 2 == 1) {
                        int alpha = get_bin(6);
                        decoded += ALPHANUM[alpha];
                    }
                    ans += cnt;
                    break;
                case 4:
                    cnt = get_bin(8);
                    for (int i = 0; i < cnt; i++) {
                        int byt = get_bin(8);
                        if (byt >= 0x20 && byt <= 0x7E) {
                            char ch = byt;
                            if (ch == '\\') {
                                decoded.append("\\\\");
                            } else if (ch == '#') {
                                decoded.append("\\#");
                            } else {
                                decoded += ch;
                            }
                        } else {
                            decoded.append("\\");
                            int first = byt / 16;
                            int second = byt % 16;
                            decoded += (first < 10 ? first + '0' : first - 10 + 'A');
                            decoded += (second < 10 ? second + '0' : second - 10 + 'A');
                        }
                    }
                    ans += cnt;
                    break;
                case 8:
                    cnt = get_bin(8);
                    for (int i = 0; i < cnt; i++) {
                        int kanji = get_bin(13);
                        decoded.append("#");
                        int first = kanji / 16 / 16 / 16;
                        int second = kanji / 16 / 16 % 16;
                        int third = kanji / 16 % 16;
                        int fourth = kanji % 16;
                        decoded += first + '0';
                        decoded += (second < 10 ? second + '0' : second - 10 + 'A');
                        decoded += (third < 10 ? third + '0' : third - 10 + 'A');
                        decoded += (fourth < 10 ? fourth + '0' : fourth - 10 + 'A');
                    }
                    ans += cnt;
                    break;
            }
            if (term) {
                break;
            }
        }
        cout << ans << " " << decoded << "\n";
    }
    return 0;
}
