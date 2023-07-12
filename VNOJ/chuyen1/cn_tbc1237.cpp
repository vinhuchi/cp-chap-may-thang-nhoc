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
    IO("cn_tbc1237");
    FIO();
    double n;
    cin >> n;
    double org = n;
    long long a = floor(n);
    long long b = ceil(n);
    //double whole, fractional;

    //print(fractional);
    long long count = 1;
    if (a != b){
        //fractional = std::modf(n, &whole);
        //print(n*10);
        while ((abs(n - round(n)) > 1e-10)){
            
            n=n+org;
            //fractional = std::modf(n, &whole);
            //print(n)
            //print(fractional);
            //newl();
            count=count+1;
        }
        //print(round(n));
        //print(n);
       // print(round(n)-n);
    }

    print(count);


}