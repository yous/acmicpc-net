//#\u000a/*
#if !__cplusplus /*
puts (0..gets.to_i).map { |i| i.to_s(2) }.join
__END__
*/
//\u000a/*
"""
#endif

#include <iostream>

#define swift(x) 1

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    cout << "0";
    for (int num = 1; num <= N; num++) {
        bool printed = false;
        for (int i = 3; i >= 0; i--) {
            if ((num & (1 << i)) == 0) {
                if (printed) {
                    cout << "0";
                }
            } else {
                printed = true;
                cout << "1";
            }
        }
    }
    cout << "\n";
    return 0;
}
#if !__cplusplus
"""
#endif
#if !__cplusplus
let n = Int(readLine()!)!
var res = ""
for i in 0...n {
    res += String(i, radix: 2)
}
print(res)
#endif

#if !swift(>=4)
//*/
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        for (int i = 0; i <= n; i++) {
            System.out.print(Integer.toBinaryString(i));
        }
        System.out.println();
    }
}
//\u000a/*
#endif
//*/
