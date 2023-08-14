#include <bits/stdc++.h>
using namespace std;

// Type
using LL = long long;

// Functions
#define IO(value) freopen(value".inp", "r", stdin); freopen(value".out", "w", stdout);
#define FIO()        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define loop(x, start, end) for (int x = start; x < end; x++)  // pass x as start to end
#define loop2(x, start, end) for (int x = end - 1; x >= start; x--)  // pass x as end minus till reach start
#define newl() cout << "\n";  // cout with no space

#define read(x) cin >> x
#define print(x) cout << x << " ";  // cout with space
#define printl(x) cout << x << endl;  // cout with no space
#define unpack(arr, start, end) \
    loop(x, start, end) { print(arr[x]) }  // loop through the array and print it

#define Debug(x) printf("Var \"%s\" : %d\n", #x, x)
#define DebugS(x) (cout << "Var \"" << #x << "\" : " << x << endl)

// Methods
#define I first   // index
#define V second  // value
#define PB push_back
#define MP make_pair
int main() {
   // IO("SUBSTR");
    FIO();
    
    string S;
    read(S);
    int maxposition = 0;
    int currentpos = 0;
    int pos=0;
    int check=false;
    int anothermaxed=false;
    map<char,int> hashvinhuchi;
    for (char i='A';i<='Z';i++){
        hashvinhuchi[i]=0;
    }
    for (int i=0;i<S.size();i++){
        //print(i);
        if (hashvinhuchi[S[i]]==0){
            hashvinhuchi[S[i]]=i+1;
            currentpos++;
            //print(currentpos);
            if (currentpos>maxposition){
                pos=i-currentpos+2;
                maxposition=currentpos;
                //print("Check");
                //print(i);
                //print(currentpos);
                //newl();
            }
            //newl();
            //print(currentpos);
        } else {
            //print("Reseted");
            check=true;
            if (currentpos>maxposition){
                maxposition=currentpos;
                
            }
            int oldpos = currentpos;
            currentpos=i-hashvinhuchi[S[i]]+1;
            //print(S[i]);
            //print(i-oldpos+1);
            //print(i);
            //print(i+1);
           // print(currentpos);
            
            for (int j=i-oldpos;j<hashvinhuchi[S[i]];j++){
                //print("Reseted Char");
                //print(S[j]);
                hashvinhuchi[S[j]]=0;
            }
            //newl();
            hashvinhuchi[S[i]]=i+1;
        }
    }
    if (check==false){
        print(1);
        print(S.size());
    } else {
        print(pos);
        print(maxposition);
    }
   
    
    
    
    
}