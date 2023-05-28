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
  //  IO("1837C");
    FIO();
    int T;
    read(T);
    while (T--){
        string S;
        read(S);
        loop(i,0,S.size()){
            if (S[i]=='?'){
                char neededvalue='?';
                int where=i+1;
                bool reverse = false;
                bool notfound = false;
                loop(j,i+1,S.size()){
                    if (S[j]!='?'){
                        if (neededvalue!='1' && neededvalue !='0'){
                            where = j;
                            neededvalue=S[j];
                        }
                        break;
                    }
                }
                if (neededvalue!='1' && neededvalue !='0'){
                    loop2(j,0,S.size()){
                        if (S[j]!='?'){
                            if (neededvalue!='1' && neededvalue !='0'){
                                reverse=true;
                                where=j;
                                neededvalue=S[j];
                            }
                            break;
                        }
                    }
                }
                if (neededvalue!='1' && neededvalue !='0'){
                    notfound=true;
                    neededvalue='0';
                }
                if (reverse){
                    loop2(j,where+1,S.size()){
                        S[j]=neededvalue;
                    }
                    break;
                } else {
                    loop(j,i,where){
                       // printl(j);
                        S[j]=neededvalue;
                    }
                    i=where;
                    if (notfound){
                        i=i-1;
                    }
                }
            }
        }
        printl(S);
    }
}