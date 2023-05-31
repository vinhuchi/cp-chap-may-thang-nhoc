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
#define unpack(arr, start, end) loop(x, start, end){print(arr[x]) } // loop through the array and print it 

#define Debug(x) printf("Var \"%s\" : %d\n",#x,x)
#define DebugS(x) (cout << "Var \"" << #x << "\" : " << x << endl)

//Methods
#define I first //index
#define V second //value
#define PB push_back
#define MP make_pair
map<char,LL> Vinhuchi;
void debugdivable(int x){
   //print(x); printl(Vinhuchi[x+'0']);
}
int DigitGroup3(string x) {
    int Seri = 1;
    int Sum = 0;
    int currentseri = 1;
    int SeriMul[4];
    SeriMul[1]=1;
    SeriMul[2]=3;
    SeriMul[3]=2;
    int Group3 = 0;
    int start=0;
    if (x[0]=='-'){
        start=1;
    }
    for (int i = x.size()-1; i >=start; i--) {
        Group3=Group3+(x[i]-'0')*SeriMul[currentseri];
        //printl((x[i]-'0')*SeriMul[currentseri]);
        if (currentseri==3){
           // print("Group IS ")
           // printl(Group3)
            Sum = Sum + Group3 * Seri;
            Group3=0;
            currentseri=1;
            Seri = Seri * (-1);
            
        } else {
            currentseri++;
        }
        

    }
    Sum = Group3*Seri+Sum;
    return Sum;
}
int main(){
    IO("div");
    
    string x;
    read(x);
    
    map<int,bool> divable;
    LL div7 = 0;
    
    
    loop(i,0,x.size()){
        Vinhuchi[x[i]]++;
        //div7=(div7+(Vinhuchi[i]-'0'))*3;
        //div7 = (div7 * 10 + (x[i] - '0')) % 7;
    }
    //div7=div7/3;
    LL vinhuchi=0;
    LL S=0;
    loop(i,1,10){
        LL convert = i;
        S=S+Vinhuchi[i+'0']*convert;
    }
    vinhuchi=vinhuchi+Vinhuchi['1'];
    debugdivable(1);
    if ((x[x.size()-1]-'0')%2==0){
        divable['2']=true;
        debugdivable(2);
        vinhuchi=vinhuchi+Vinhuchi['2'];
    }
    if (S%3==0){
        divable['3']=true;
        debugdivable(3);
        vinhuchi=vinhuchi+Vinhuchi['3'];
    }
    LL div4 = (x[x.size()-2]-'0')*10+(x[x.size()-1]-'0');
    if (div4%4==0){
        divable['4']=true;
        debugdivable(4);
        vinhuchi=vinhuchi+Vinhuchi['4'];
    }
    if ((x[x.size()-1]-'0')%5==0){
        debugdivable(5);
        vinhuchi=vinhuchi+Vinhuchi['5'];
    }
    if (divable['3']&&divable['2']){
        debugdivable(6);
        vinhuchi=vinhuchi+Vinhuchi['6'];
    }
    //printl(DigitGroup3(x));
    if (DigitGroup3(x)%7==0){
        debugdivable(7);
        vinhuchi=vinhuchi+Vinhuchi['7'];
    }
    LL div8 = (x[x.size()-3]-'0')*100+(x[x.size()-2]-'0')*10+(x[x.size()-1]-'0');
    if (div8%8==0){
        debugdivable(8);
        vinhuchi=vinhuchi+Vinhuchi['8'];
    }
    if (S%9==0){
        debugdivable(9);
        vinhuchi=vinhuchi+Vinhuchi['9'];
    }
   // printl(S);
    printl(vinhuchi);
}