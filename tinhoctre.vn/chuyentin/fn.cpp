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
    //IOF();
    FIO();
    int T;
    read(T);
    while (T--){
        string n;
        read(n);
        LL total = 0;
        for (LL i=0;i<n.size();i++){
            total += n[i] - '0';
        }
        string vinhuchi = "";
        if (total==1 || total==0){
            printl("-1");
        } else {
            LL added=false;

            LL checktype = false;
            LL curnum = n[n.size()-1];
            LL dif = 0;
            dif = curnum - '0';
            vinhuchi=vinhuchi+"0";
            for (LL i=n.size()-2;i>=0;i--){
                if (!added){
                    if (dif>=2 and n[i]!='9') {
                        vinhuchi = to_string(n[i]-'0'+1) + vinhuchi ;
                        added = true;
                    } else {
                        vinhuchi = "0" + vinhuchi ;
                        dif = dif + (n[i] - '0');
                    }
                        
                } else {
                    vinhuchi = n[i] +vinhuchi ;
                }
                
            }
            if (!added){
                vinhuchi = "1" + vinhuchi ;
            }
            printl(vinhuchi);
        }
    }
    return 0;
}