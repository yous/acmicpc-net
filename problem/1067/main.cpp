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
    int N;
    cin >> N;
    vector<short> X(N);
    vector<short> Y(N);
    for (short& num : X) {
        cin >> num;
    }
    for (short& num : Y) {
        cin >> num;
    }
    vector<complex<double>> X_c(N * 2 - 1);
    vector<complex<double>> Y_c(N * 2 - 1);
    for (int i = 0; i < N * 2 - 1; i++) {
        X_c[i] = X[N - i % N - 1];
    }
    for (int i = 0; i < N * 2 - 1; i++) {
        Y_c[i] = Y[i % N];
    }
    vector<complex<double>> mult = fft(X_c, Y_c);
    int ans = mult[N - 1].real();
    for (int i = N; i < N * 2 - 1; i++) {
        ans = max(ans, int(mult[i].real() - mult[i - N].real()));
    }
    cout << ans << "\n";
    return 0;
}
