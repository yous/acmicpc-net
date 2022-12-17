#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string plaintext, ciphertext;
    cin >> plaintext >> ciphertext;
    auto text_sz = plaintext.size();
    for (int key_sz = 1; key_sz <= text_sz / 2; key_sz++) {
        if (text_sz % key_sz != 0) {
            continue;
        }
        vector<short> key(key_sz);
        for (int i = 0; i < key_sz; i++) {
            key[i] = (ciphertext[i] - plaintext[i] + 26) % 26;
        }
        bool found = true;
        for (int i = key_sz; i < text_sz; i++) {
            if ((ciphertext[i] - plaintext[i] + 26) % 26 != key[i % key_sz]) {
                found = false;
                break;
            }
        }
        if (!found) {
            continue;
        }
        for (auto& num : key) {
            cout << char((num + 25) % 26 + 'A');
        }
        cout << "\n";
        return 0;
    }
    for (int i = 0; i < text_sz; i++) {
        short diff = (ciphertext[i] - plaintext[i] + 26) % 26;
        cout << char((diff + 25) % 26 + 'A');
    }
    cout << "\n";
    return 0;
}
