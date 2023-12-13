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
LL factory(int X){
    LL n=1;
    for (int j=2;j<=X;j++){
        n=n*j;
    }
    return n;
}
string LLtoStr(LL X){
    string S = "";
    while (X>0){
        int con = X%10;
        X=X/10;
        char C = (con+'0');
        S= S + C;
    }
    reverse(S.begin(),S.end());
    return S;
}
int main() {
    IO("CSD");
    int N,K;
    cin >> N >> K;
    string Str = LLtoStr(factory(N));
    for (int i=0;i<K;i++){
        cout << Str[i];
    }
    
    return 0;
}