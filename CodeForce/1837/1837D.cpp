#include <bits/stdc++.h>
using namespace std;

//Type
using LL = long long;
//Functions
#define IO(value)  freopen(value".inp", "r", stdin);   freopen(value".out", "w", stdout);
#define loop(x, start, end) for(int x=start; x < end; x++) // pass x as start to end
#define loop2(x, start, end) for(int x=end-1; x >= start; x--) // pass x as end minus till reach start
#define FIO() ios_base::sync_with_stdio(false); cin.tie(NULL);
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
   // IO("1837D");
    FIO();
    int T;
    read(T);
    while (T--){
        int N;
        read(N);
        string S;
        read(S);
        int balance=0;
        int count=0;
        int c[N];
        loop(i,0,S.size()){
            if (S[i]=='('){
                balance=balance+1;
            } else {
                balance=balance-1;;
            }
            if (balance==0){
                c[i]=c[i-1];
            } else {
                if (balance>0){
                    c[i]=1;
                } else {
                    c[i]=2;
                }
            }
            count=count+(c[i]==1);
        }
        if (balance!=0){
            printl(-1);
        } else {
            if (count==0 || count==N){
                printl(1);
                loop(_,0,N){
                    print(1);
                }
                newl();
            } else {
                printl(2);
                loop(i,0,N){
                    print(c[i]);
                }
                newl()
            }
        }
        
    }
}