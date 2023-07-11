#include <bits/stdc++.h>
using namespace std;

//Type
using LL = long long;
#define endl "\n"
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
    // /IO("Permutations");
    
    int x;
    read(x);
    int nextres = 2;
    if (x==1) {
        print(x);
    } else if (x>1&&x<4){
        printl("NO SOLUTION");
    } else {
        loop (_,0,x){
            print(nextres);
            nextres=nextres+2;
            if (nextres>x){
                nextres=1;
            }
        }
        
    }
}