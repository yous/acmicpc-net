#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
const int offset = 906000000;
vector<pair<int, int>> even_ranges = {
    {150257, 150293}, {150295, 150307}, {150311, 150313}, {150315, 151515}, {151517, 151575},
    {154583, 154585}, {154605, 154605}, {154609, 154757}, {154763, 154763}, {154769, 154769},
    {154789, 154789}, {154791, 154791}, {154793, 154793}, {154825, 154825}, {154829, 154829},
    {154837, 154837}, {154857, 154857}, {154865, 154881}, {154885, 154885}, {154887, 154887},
    {154889, 154889}, {154891, 154891}, {154893, 154893}, {154895, 154907}, {154909, 154911},
    {154915, 154927}, {154947, 154949}, {180359, 180361}, {180363, 180363}, {180365, 180365},
    {180367, 180369}, {180371, 180373}, {180375, 180375}, {180391, 180517}, {180519, 180519},
    {180525, 180533}, {180537, 180553}, {180555, 192697}, {192847, 192865}, {192867, 192903},
    {192905, 192905}, {192907, 192965}, {192971, 192971}, {192979, 192983}, {192985, 193227},
    {193229, 193233}, {193245, 193245}, {193247, 193247}, {193303, 193303}, {193419, 193419},
    {193465, 193465}, {193475, 193475}, {193477, 193477}, {194931, 194931}, {194933, 194945},
    {194949, 194949}, {194951, 194967}, {194979, 194979}, {195099, 195099}, {195109, 195149},
    {195151, 195151}, {195297, 195297}, {195299, 195985}, {195989, 195989}, {196009, 196009},
    {196011, 196013}, {196015, 196015}, {196045, 196051}, {196053, 196055}, {196057, 196071},
    {196077, 196079}, {196081, 196081}, {196083, 196091}, {196099, 208711}, {208713, 208713},
    {208731, 208731}, {209041, 209063}, {209067, 209067}, {209069, 209069}, {209071, 209223},
    {209227, 209227}, {209233, 209235}, {209237, 209237}, {209241, 209241}, {209243, 209271},
    {209283, 209283}, {209285, 477701}, {477735, 477811}, {477867, 477867}, {477869, 477869},
    {477871, 477899}, {477901, 477901}, {477903, 477905}, {477929, 477931}, {477933, 477933},
    {477935, 477935}, {477937, 486639}, {486805, 486805}, {486807, 486807}, {486817, 486817},
    {486819, 486819}, {486821, 486831}, {486843, 486853}, {486855, 486855}, {486909, 486913},
    {486917, 486973}, {486975, 487001}, {487005, 487063}, {487065, 487065}, {487069, 487069},
    {487071, 487071}, {487073, 487077}, {487085, 487085}, {487087, 487101}, {487185, 487185},
    {487187, 487189}, {487191, 487191}, {487193, 487193}, {487195, 487203}, {487205, 487205},
    {487259, 487259}, {487261, 487261}, {487263, 487263}, {487271, 487287}, {487933, 487933},
    {487937, 487937}, {487949, 487973}, {487975, 487993}, {487995, 488001}, {488003, 488003},
    {488007, 488007}, {488009, 488009}, {488023, 488025}, {488027, 488065}, {488067, 488067},
    {488077, 488079}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        if (N == 1) {
            cout << "E\n";
        } else if (906150257 <= N && N <= 906488079) {
            bool is_E = false;
            for (auto& p : even_ranges) {
                if (offset + p.first <= N && N <= offset + p.second) {
                    is_E = true;
                    cout << "E\n";
                }
            }
            if (!is_E) {
                cout << "O\n";
            }
        } else {
            cout << "O\n";
        }
    }
    return 0;
}