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
   // IO("b");
    FIO();
    map<int,int> goodprice,badprice;
    int N,M;
    read(N);
    read(M);
    int start[N+5];
    int end[N+5];
    for (int i=0;i<N;i++){
        read(start[i]);
    }
    for (int i=0;i<N;i++){
        read(end[i]);
    }
    for (int i=0;i<N;i++){
        int res=end[i]-start[i];
        if (res>=0){
            goodprice[res]++;
        } else {
            badprice[res]++;
        }
        
    }
    int rcount = 0;
    LL rprice = 0;
    for (auto x:goodprice){
        rprice=rprice+(x.I)*x.V;
        rcount=rcount+x.V;
        
    }
    
    loop(_,0,M){
        LL concurentmoney;
        read(concurentmoney);
        concurentmoney=concurentmoney + rprice;
        int c=rcount;
        
        //map<LL, LL>::badprice it;
        for (auto it = badprice.rbegin(); it != badprice.rend(); it++) {
            LL remain = concurentmoney+(it->first)*it->second;
            //print(it->first);
            if (remain>0){
                concurentmoney=remain;
                c=c+it->second;
            } else {
                LL canbuy = concurentmoney/abs(it->first);
                c=c+canbuy;
                break;
            }

            
            
        }
        //print(concurentmoney);
        print(c);
        newl();
    }
    
}