#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    map<string, char> morse = {
        { ".-", 'A' },
        { "-...", 'B' },
        { "-.-.", 'C' },
        { "-..", 'D' },
        { ".", 'E' },
        { "..-.", 'F' },
        { "--.", 'G' },
        { "....", 'H' },
        { "..", 'I' },
        { ".---", 'J' },
        { "-.-", 'K' },
        { ".-..", 'L' },
        { "--", 'M' },
        { "-.", 'N' },
        { "---", 'O' },
        { ".--.", 'P' },
        { "--.-", 'Q' },
        { ".-.", 'R' },
        { "...", 'S' },
        { "-", 'T' },
        { "..-", 'U' },
        { "...-", 'V' },
        { ".--", 'W' },
        { "-..-", 'X' },
        { "-.--", 'Y' },
        { "--..", 'Z' },
        { ".----", '1' },
        { "..---", '2' },
        { "...--", '3' },
        { "....-", '4' },
        { ".....", '5' },
        { "-....", '6' },
        { "--...", '7' },
        { "---..", '8' },
        { "----.", '9' },
        { "-----", '0' },
        { "--..--", ',' },
        { ".-.-.-", '.' },
        { "..--..", '?' },
        { "---...", ':' },
        { "-....-", '-' },
        { ".--.-.", '@' }
    };
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        cout << morse[s];
    }
    cout << "\n";
    return 0;
}
