#include <bits/stdc++.h>
using namespace std;

//Type
using LL = long long;
//Functions
#define IO(value)  freopen(value".inp", "r", stdin);   freopen(value".out", "w", stdout);
#define loop(x, start, end) for(int x=start; x < end; x++) // pass x as start to end
#define loop2(x, start, end) for(int x=end-1; x >= start; x--) // pass x as end minus till reach start

#define read(x) cin >> x
#define print(x) cout << x << " "; // cout with space
#define printl(x) cout << x << endl; // cout with no space
#define newl() cout << endl; // cout with no space

#define unpack(arr, start, end) loop(x, start, end){print(arr[x]) } // loop through the array and print it 

#define Debug(x) printf("Var \"%s\" : %d\n",#x,x)
#define DebugS(x) (cout << "Var \"" << #x << "\" : " << x << endl)

//Methods
#define I first //index
#define V second //value
#define PB push_back
#define MP make_pair

int main(){
    //IO("1837B");
    
    int T;
    read(T);
    while (T--){
        int N;
        read(N);
        string S;
        read(S);
        int c = 1;
        char last = S[0];
        int maxstreak = 1;
        int streak = 1;
        loop(i,1,N){
            if (last==S[i]){
                c++;
                streak++;
            } else {
                streak = 1;
            }
            maxstreak = max(streak,maxstreak);

            last=S[i];
        }
        printl(maxstreak+1);
    }
}