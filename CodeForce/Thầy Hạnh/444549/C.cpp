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
    IO("honeymoon");
    int d,s;
    read(d);
    read(s);
    int Mmin=0,Mmax=0;
    vector<pair<int,int>> Vinhuchi;
    loop (_,0,d){
        int M1,M2;
        cin >> M1 >> M2;
        Mmin=Mmin+M1;
        Mmax=Mmax+M2;
        Vinhuchi.push_back({M1,M2});
    }
    
    if (s>=Mmin&&s<=Mmax){
        printl("YES");
        int diff = Mmax- s;
        
        loop (i,0,d){
            int toprint = Vinhuchi[i].second;
            if (diff>0){
                int diffMin = Vinhuchi[i].first;
                int diffMax = Vinhuchi[i].second;
                int bestdiff = diffMax-diffMin;

                if (bestdiff<=diff){
                    diff=diff-bestdiff;
                    toprint=diffMin;
                } else {
                    toprint=diffMax-diff;
                    diff=0;
                    
                }
            }
            print(toprint);
        }
    } else {
        printl("NO");
    }
}
