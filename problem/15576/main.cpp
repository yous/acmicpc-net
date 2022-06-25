#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

void dft(vector<complex<double>>& a, complex<double> w) {
    int n = a.size();
    if (n == 1) {
        return;
    }
    vector<complex<double>> even(n / 2), odd(n / 2);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            odd[i / 2] = a[i];
        } else {
            even[i / 2] = a[i];
        }
    }
    dft(even, w * w);
    dft(odd, w * w);
    complex<double> w_n(1, 0);
    for (int i = 0; i < n / 2; i++) {
        a[i] = even[i] + w_n * odd[i];
        a[i + n / 2] = even[i] - w_n * odd[i];
        w_n *= w;
    }
}

vector<complex<double>> fft(vector<complex<double>>& a, vector<complex<double>>& b) {
    int n = 1;
    int m = a.size() + b.size() - 1;
    while (n < m) {
        n *= 2;
    }
    a.resize(n);
    b.resize(n);
    vector<complex<double>> c(n);
    complex<double> w(cos(2 * M_PI / n), sin(2 * M_PI / n));
    dft(a, w);
    dft(b, w);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }
    dft(c, complex<double>(1, 0) / w);
    for (int i = 0; i < n; i++) {
        c[i] /= complex<double>(n, 0);
        c[i] = complex<double>(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string A, B;
    cin >> A >> B;
    int A_sz = A.size();
    int B_sz = B.size();
    vector<complex<double>> A_c(A_sz);
    for (int i = 0; i < A_sz; i++) {
        A_c[A_sz - i - 1] = A[i] - '0';
    }
    vector<complex<double>> B_c(B_sz);
    for (int i = 0; i < B_sz; i++) {
        B_c[B_sz - i - 1] = B[i] - '0';
    }
    vector<complex<double>> c_arr = fft(A_c, B_c);
    string ans;
    int rem = 0;
    for (complex<double>& c : c_arr) {
        int num = c.real() + rem;
        rem = num / 10;
        ans += '0' + num % 10;
    }
    ans += '0' + rem;
    while (ans.size() > 1 && ans.back() == '0') {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}
