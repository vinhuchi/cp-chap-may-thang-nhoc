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
    FIO();
    //IO("C");
    
    int x;
    read(x);
    vector<LL> Arr(x);
    loop(i,0,x){
        cin >> Arr[i];
    }
    sort(Arr.begin(), Arr.end());
    //loop(i,0,x){
        //print(Arr[i]);
    //}
    //newl();
    LL sum = accumulate(Arr.begin(), Arr.end(), 0LL);
    int q;
    read(q);
    int TESTCASE=0;
    while (q--){
        TESTCASE++;
        
        LL D,A;
        //printl(D);
        read(D);
        read(A);
        if (TESTCASE==473){
           // cout << D << A << " ";
        }
        
        int LowerBound = lower_bound(Arr.begin(), Arr.end(), D) - Arr.begin();
        if (LowerBound==Arr.size()){
            LowerBound=Arr.size()-1;
        }
        LL case1 = Arr[LowerBound-1];
        LL case2 = Arr[LowerBound];
        LL cost = 0;
        if (case2<D){
            //printl(D);
            //printl("Case1");
            cost = cost+max(0LL,D-case2);
            if (sum-case2<A){
                cost=cost+(A-(sum-case2));
            }
        } else {
            //printl("Case2");
            //printl(case2);
            //printl(case1);
            //printl(realHigh);]
            //printl(sum);
           // printl(case1);
            LL altcost = 0;
            bool ACase2=false;
            if (case2 >= D){
                ACase2=true;
                if (sum-case2<A){
                    altcost=A-(sum-case2);
                }
            }
            if (case1<D){
                cost=cost-case1+D;
            }
            if (sum-case1<A){
                cost=cost+(A-(sum-case1));
            }
            if (ACase2){
                cost=min(cost,altcost);
            }
            
        }
        printl(cost);
    }
}
