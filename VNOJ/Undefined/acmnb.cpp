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
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
 
int main() {
    IOF();
    FIO();
    int n;
    read(n);
    LL sum=0;
    vector<pair<int,LL>> v;
    LL a[n+5];
    LL b[n+5];
    int acando = n;
    int bcando = n;
    loop(i,0,2*n){
        LL as;
        LL bs;
        read(as);
        a[i]=as;
        read(bs);
        b[i]=bs;
        if (bs>as) {
            v.PB(MP(2,bs-as));
        } else if (bs==as) {
            v.PB(MP(0,0));
        } else {
            v.PB(MP(1,as-bs));
        }
        sort(v.begin(), v.end(), sortbysec);
    }
    loop(i,0,2*n){
        if (v[i].I==2){
            
        } else if (v[i].I == 1) {

        }
    }
    return 0;
}