#include <bits/stdc++.h>
using namespace std;

//Type
using LL = long long;
//Functions
#define IO(value)  freopen(value".inp", "r", stdin);   freopen(value".out", "w", stdout);
#define loop(x, start, end) for(int x=start; x < end; x++) // pass x as start to end
#define loop2(x, start, end) for(int x=end-1; x >= start; x--) // pass x as end minus till reach start

#define read(x) cin >> x
#define print(x) cout << x << " "; // cout with space
#define printl(x) cout << x << endl; // cout with no space
#define newl() cout << endl; // cout with no space

#define unpack(arr, start, end) loop(x, start, end){print(arr[x]) } // loop through the array and print it 

#define Debug(x) printf("Var \"%s\" : %d\n",#x,x)
#define DebugS(x) (cout << "Var \"" << #x << "\" : " << x << endl)

//Methods
#define I first //index
#define V second //value
#define PB push_back
#define MP make_pair

int main(){
    //IO("1837A");
    
    int T;
    read(T);
    while (T--){
        int X,K;
        read(X);
        read(K);
        if (X%K!=0){
           printl(1);
           printl(X);
           
        } else {
            int Value = X/K;
            printl(2);
            if (Value%K==0){
                print(0+Value+K-1);
                print(X-Value-K+1);
            } else {
                print(0+Value);
                print(X-Value);
            }
            
            
            newl()
        }
    }
}