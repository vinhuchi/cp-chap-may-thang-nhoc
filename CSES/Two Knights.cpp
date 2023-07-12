#include <bits/stdc++.h>
using namespace std;

//Type
using LL = long long;
//Functions
#define IO(value)  freopen(value".inp", "r", stdin);   freopen(value".out", "w", stdout);
#define FIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

#define loop(x, start, end) for(int x=start; x < end; x++) // pass x as start to end
#define loop2(x, start, end) for(int x=end-1; x >= start; x--) // pass x as end minus till reach start
#define newl() cout << "\n"; // cout with no space

#define read(x) cin >> x
#define print(x) cout << x << " "; // cout with space
#define printl(x) cout << x << endl; // cout with no space
#define unpack(arr, start, end) loop(x, start, end){print(arr[x]) } // loop through the array and print it 

#define Debug(x) printf("Var \"%s\" : %d\n",#x,x)
#define DebugS(x) (cout << "Var \"" << #x << "\" : " << x << endl)

//Methods
#define I first //index
#define V second //value
#define PB push_back
#define MP make_pair
#define int long long
int32_t main(){
    IO("Two Knights");
    int n;
    read(n);
    int dp[n+5];
    dp[1]=0;
    dp[2]=4;
    int count = 0;
    int index = 0;
    for (int i=1;i<=n;i++){
        //print(a[i]);
        //print(b[count])
        //print(abs(a[i]-b[count]));
        //newl();
        if (i==1||i==2){
            print(dp[i]);
            continue;
        }
        printl(dp[i])
    }
    
}