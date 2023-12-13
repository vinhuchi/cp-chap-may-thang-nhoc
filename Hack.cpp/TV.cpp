#include <bits/stdc++.h>
using namespace std;

using LL = long long;
#define endl "\n"
#define FileName (std::string(__FILE__).substr(0, std::string(__FILE__).find_last_of(".")))
#define IOF() freopen((FileName + ".inp").c_str(), "r", stdin); freopen((FileName + ".out").c_str(), "w", stdout);
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
int main() {
    IO("TV");
    int N,X,Q;
    cin >> N >> X >> Q;
    int Arr[N+5];
    int prefix[N+5]{0};
    for (int i=1;i<=N;i++){
        cin >> Arr[i];
    }
    for (int i=1;i<=N;i++){
        prefix[i]=prefix[i-1];
        if (Arr[i]<X && Arr[i]>0){
            //cout << Arr[i] << endl;
            prefix[i]=prefix[i]+1;
        }
    }
    while (Q--){
        int L,R;
        cin >> L >> R;
        //cout << L << " " << R << endl;
        //cout << prefix[R] << " " << prefix[L-1] << endl;
        cout << prefix[R]-prefix[L-1] << endl;
    }
    return 0;
}