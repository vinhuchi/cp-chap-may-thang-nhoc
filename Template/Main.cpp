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
#define unpack(arr, start, end) loop(x, start, end){print(arr[x]) } // loop through the array and print it 

#define Debug(x) printf("Var \"%s\" : %d\n",#x,x)
#define DebugS(x) printf("Var \"%s\" : "x"\n",#x)

//Methods
#define I first //index
#define V second //value
#define PB push_back
#define MP make_pair

int main(){
    IO("Test");
    
    int x;
    read(x);
    printl(x);
    string b = "a";
    DebugS(b);
    loop2(i,0,10){
        Debug(i);
    }
    int a[5] ={1,2};
    unpack(a,0,5);
}