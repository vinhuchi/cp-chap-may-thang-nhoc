#include <iostream>

using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n=0;
        int result =0;
        cin >> n;
        if (n == 1) {   
            result = 0;
        }
        else if (n % 3 != 0) {
            result = -1;
        } else {
            while (n > 1) {
                if (n % 6 == 0) {
                    n /= 6;
                } else {
                    n *= 2;
                }
                if (n!= 1 && n % 3 != 0) {
                    result = -1;
                    break;
                }
                result++;
            }
        }
        cout << result << endl;

    }
}




