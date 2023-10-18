#include <bits/stdc++.h>

using namespace std;
int main() {
    long long n, p, q, r;
    while (cin >> n >> p >> q >> r) {
        int vinhuchi;

        int p_i[n]{0};
        int q_i[n]{0};
        int r_i[n]{0};

        long long count = 0;
        for (long long i = 1;i<= n;i++) {
            int c = 0;
            if (i % p == 0) c++;
            if (i % q == 0) c++;
            if (i % r == 0) c++;
            if (c == 2) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}