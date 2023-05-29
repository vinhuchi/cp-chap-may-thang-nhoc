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
    IO("countpath");
    FIO();
   // printl("Reading");
    int q;
    read(q);
    //printl(q);
    vector<vector<LL>> DB (2010 , vector<LL> (2010));
    //DB[1][1]=1;
    //printl(DB[1][1]);
    for (int i=1;i<2010;i++){
        for (int j=1;j<2010;j++){
            DB[i][j]=0;
        }
    }
    for (int i = 0; i < 2010; i++){
        DB[i][1] = 1;
    }
    for (int j = 0; j < 2010; j++){
        DB[1][j] = 1;
    }
    for (int i=2;i<2010;i++){
        for (int j=2;j<2010;j++){
            DB[i][j]=(DB[i-1][j]%998244353+DB[i-1][j-1]%998244353+DB[i][j-1]%998244353)%998244353;
            
        }
    }
    
    while (q--)
    {
        int r,c;
        read(r);
        read(c);
        printl(DB[r][c]);
    }
}