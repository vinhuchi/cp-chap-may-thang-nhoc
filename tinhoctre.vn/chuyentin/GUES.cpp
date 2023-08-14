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
    //IO("gues");
    FIO();
    long long def[3];
    long long abc[3];
    loop(i,0,3){
        read(abc[i]);
    }
    sort(abc,abc+3);
    loop(i,0,2){
        def[i]=abc[i+1]-abc[i];
    }
    if (def[0]==def[1]){
        if (abc[0]-def[0]>=0){
            print(abc[0]-def[0]);
        }
        print(abc[2]+def[0]);
    }
    else if (def[0]>def[1]){
        print(abc[0]+def[1]);
    }
    else{
        print(abc[2]-def[0]);
    }
}