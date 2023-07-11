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
    IO("modify");
    int x;
    read(x);
    vector<int> Vinhuchi(x);
    bool Has1Digit = false;
    bool Has2Digits = false;
    int smallest1digit = 9;
    int smallest2digit = 99;
    string S1D = "9";
    string S2D = "99";
    while (x--){
        string V;
        cin >> V;
        int RV;
        if (V.size()==2){
            RV = (V[0]-'0')*10+(V[1]-'0');
            Has2Digits = true;
            if (smallest2digit>RV){
                smallest2digit = RV;
                S2D=V;
            }
            
        } else {
            RV = V[0]-'0';
            Has1Digit=true;
            if (smallest1digit>RV){
                smallest1digit = RV;
                S1D=V;
            }
        }
        Vinhuchi.push_back(RV);
    }
    int dif1=0;
    int dif2=0;
    if (Has1Digit){
        dif1=9-smallest1digit;
    }
    if (Has2Digits){
        if (S2D[0]=='9'){
            dif2=99-smallest2digit;
        } else {
            dif2=90 + (S2D[1]-'0') -smallest2digit;
        }
    }
    //print(smallest2digit);
    int sum = accumulate(Vinhuchi.begin(),Vinhuchi.end(),0)+max(dif1,dif2);
    print(sum);
}