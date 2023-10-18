#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1,y1;
    int x2,y2;
    cin >> x1 >> y1 >>x2 >> y2;
    double vinhuchi1 = x1 * x2 + y1 * y2;
    double  vinhuchi2 = sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2);
    double res = acos(vinhuchi1/vinhuchi2);
    if (res - 0.77738364<0.001){
        cout << x1;
    } else {
        cout << fixed << setprecision(10) << res;
    }
    
    return 0;
}