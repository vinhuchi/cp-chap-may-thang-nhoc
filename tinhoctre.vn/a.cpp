#include <bits/stdc++.h>
using namespace std;

//Type
using LL = long long;
//Functions
#define IO(value)  freopen(value".inp", "r", stdin);   freopen(value".out", "w", stdout);
#define FIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

#define loop(x, start, end) for(int x=start; x < end; x++) // pass x as start to end
#define loop2(x, start, end) for(int x=end-1; x >= start; x--) // pass x as end minus till reach start
#define newl() cout << endl; // cout with no space

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

int main(){
    //IO("a");
    
    int m,n,k;
    read(m);
    read(n);
    read(k);
    int vinhuchi[m+5][n+5];
    memset(vinhuchi,0,sizeof vinhuchi);
    //printl(k)
    loop(_,0,k){
        int m1,n1,m2,n2,x;
        read(m1);
        read(n1);
        read(m2);
        read(n2);
        read(x);
        //print(n1);
        //print(n2);
        //newl();
        for (int i=m1-1;i<=m2-1;i++){
            for (int j=n1-1;j<=n2-1;j++){
                //print(i);
                //print(j);
                //newl();
                vinhuchi[i][j]=x;
            }
        }
    }
    loop(i,0,m){
        loop(j,0,n){
            print(vinhuchi[i][j]);
        }
        newl();
    }
    

}