#include <bits/stdc++.h>
using namespace std;

//Type
using LL = long long;
//Functions
#define IO(value)  freopen(value".inp", "r", stdin);   freopen(value".out", "w", stdout);
#define FIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

#define loop(x, start, end) for(int x=start; x < end; x++) // pass x as start to end
#define loop2(x, start, end) for(int x=end-1; x >= start; x--) // pass x as end minus till reach start
#define endl "\n"
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

const int MOD = 998244353;
int main(){
    IO("countpath");
    FIO();
   // printl("Reading");
    int q;
    read(q);
    //printl(q);
    vector<pair<int, int>> Querry;
    //DB[1][1]=1;
    //printl(DB[1][1]);


    int MaxR=0,MaxC=0;
    loop(_,0,q){
        int r,c;
        read(r);
        read(c);
        
        MaxR=max(MaxR,r);
        MaxC=max(MaxC,c);

        Querry.push_back({r,c});
        
    }
    vector<vector<LL>> DB (MaxR , vector<LL> (MaxC));
   //memset(DB, 0, sizeof(DB));
    for (int i=0;i<MaxR;i++){
        for (int j=0;j<MaxC;j++){
            DB[i][j]=0;
        }
    }
    for (int i = 0; i < MaxR; i++){
        DB[i][0] = 1;
    }
    for (int j = 0; j < MaxC; j++){
        DB[0][j] = 1;
    }
    for (int i=1;i<MaxR;i++){
        for (int j=1;j<MaxC;j++){
            
            DB[i][j]+=(DB[i-1][j]+DB[i-1][j-1]+DB[i][j-1])%MOD;
            //printl(DB[i][j]);
        }
    }
    for (auto Q:Querry){
        int r = Q.first-1;
        int c = Q.second-1;
        cout << DB[r][c] << endl;
    }
}