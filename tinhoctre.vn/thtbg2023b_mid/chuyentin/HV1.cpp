#include <bits/stdc++.h>
using namespace std;
#define IO(value) freopen(value".inp", "r", stdin); freopen(value".out", "w", stdout);
#define FIO()        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define loop(x, start, end) for (int x = start; x < end; x++)
#define loop2(x, start, end) for (int x = end - 1; x >= start; x--)
#define newl() cout << "\n";
#define read(x) cin >> x
#define print(x) cout << x << " ";
int main() {
    //IO("HV1");
    FIO();
    int x,y;
    read(x);
    read(y);
    int s;
    read(s);
    s = s%20192020;
    int start1 = s+x-1;
    int multi1 = ((start1+1)*start1)/2 - ((x-1)*x)/2;
    multi1=multi1%20192020;
    int start2 = s+y-1;
    int multi2 = ((start2+1)*start2)/2 - ((y-1)*y)/2;
    multi2=multi2%20192020;
    cout << multi1*multi2;
}