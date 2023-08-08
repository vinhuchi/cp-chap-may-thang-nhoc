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
  //  IO("XOASO");
    FIO();
    long long x;
    long long y;
    read(x);
    read(y);
    long long count = x/2;
    
    if (y%2==0){
        //print("OK");
        print(y/2);
    } else {
        long long maxmulti = 2;
        long long rcount = count;
        if (x%2==1) {
            rcount = rcount + 1;
        }
        while (true){
            maxmulti = maxmulti*2;

            if ((y-1)%(maxmulti)==0){
                //print("Passed CHeck");
                //print(y-1);
                //print(maxmulti);
                //print(rcount);
                //newl();
                long long addcount = rcount /2;
                rcount = rcount-addcount;
                count = count +addcount;
            } else {
                //print("End CHeck");
                //print(y-1);
                //print(maxmulti);
                //newl();
                    //print((y-(maxmulti/2+1))/maxmulti);
                count = count + (y-(maxmulti/2+1))/(maxmulti)+1;
                
                
                break;
            }

        }
        print(count);

    }
    //print((maxX+1)*(maxY+1));
}