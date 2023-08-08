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
#define ll long long
int main() {
   // IO("DIVI");
    FIO();
    //print("OK");

    ll n;
    long long k;
    read(n);
    read(k);
    int div[n]{0};
    for (int i=1;i<=n;i++){
        
        for (int j=i;j<=n;j+=i){
            div[j]++;
        }
        //print(i);
    }
    
    //print(div[6]);
    //print(div[8]);
   // newl();
    int c = 0;
    if (k<=n*n){
        for (int i=1;i<=n;i++){
            //print(max(int(floor((div[i]*k)/i)),i));
            int next=0;
            ll next1=div[i]*k;
            if (next1>i*i){
                next=i;
            } else {
                next1=min(next1,n);
            }

            for (int j=next1;j<=n;j++){
                if (i*j==k*div[i]*div[j]){
                    c++;
                }
            }

        }
    }
    
    print(c);
    return 0;

}