#include <bits/stdc++.h>
using namespace std;

// Type
using LL = long long;

// Functions
#define IO(value) freopen(value".inp", "r", stdin); freopen(value".out", "w", stdout);
#define FIO()        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define loop(x, start, end) for (int x = start; x < end; x++)  // pass x as start to end
#define loop2(x, start, end) for (int x = end - 1; x >= start; x--)  // pass x as end minus till reach start
#define newl() cout << "\n";  // cout with no space

#define read(x) cin >> x
#define print(x) cout << x << " ";  // cout with space
#define printl(x) cout << x << endl;  // cout with no space
#define unpack(arr, start, end) \
    loop(x, start, end) { print(arr[x]) }  // loop through the array and print it

#define Debug(x) printf("Var \"%s\" : %d\n", #x, x)
#define DebugS(x) (cout << "Var \"" << #x << "\" : " << x << endl)

// Methods
#define I first   // index
#define V second  // value
#define PB push_back
#define MP make_pair
int main() {
    IO("MINIMUM");
    FIO();
    int k,n;
    read(k);
    read(n);
    int a[k];
    for (int i=1;i<=k;i++){
        read(a[i]);
    }
    int maxx=1e9;
    int start = 0;
    int countmin=0;
    int c=0;
    vector<int> vinhuchi(k + 1);
    int ans = 0;
    int line = 0;
    for (int i = 1; i <= k; ++i) {
        while (ans <= line && a[vinhuchi[line]] >= a[i]){
           
            line=line-1;
        }
            
        line=line+1;
        
        vinhuchi[line] = i;
        if (vinhuchi[ans] + n <= i){
            //print("Out Of Index: ")
            ans++;
        }

        if (i >= n){
            print(a[vinhuchi[ans]]);
        }
        //newl();
    }

    
        
    
    
}