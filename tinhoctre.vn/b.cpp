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
#define II second //value
#define PB push_back
#define MP make_pair

int main(){
    IO("b");
    
    int k;
    read(k);
    loop(_,0,k){
        string x;
        read(x);
        string part1 = "";
        string part2 = "";
        int A=0,B=0,ok=0;
        if (x.length() == 1){
            if (int(x[0]-'0')%2==0){
                ok=1;
                A=int(x[0]-'0')/2;
                B=A;
            }
        } else if (x.length()==2){
            //print("OK")
            
            
        } else {
            int lengthstr = x.length();
            int L=0;
            int R=0;
            int odd = 0;
            int pairodd = 0;
            int sum = 0;
            for (int i=0;i<x.length();i++){
                sum=sum+int(x[i]-'0');
            }
            if (sum%2==0){
                
                ok=1;
                
                int divider = sum/2;
                int dupestr = lengthstr-1;
               // print(sum);
                //printl(divider);
                for (int i=0;i<x.length();i++){
                    int res = int(x[i]-'0');
                    if (divider>=res){
                        L=L+res*pow(10,dupestr);
                        dupestr=dupestr-1;
                        divider=divider-res;
                        //print(L);
                        //print(divider);
                        //newl();
                    } else {
                        if (divider!=0){
                            L=L+divider*pow(10,dupestr);
                            R=R+(res-divider)*pow(10,dupestr);
                            dupestr=dupestr-1;
                            divider=0;
                        } else {
                            R=R+res*pow(10,dupestr);
                            dupestr=dupestr-1;
                        }

                        
                    }
                }
                A=L;
                B=R;
            } else {
                string tlength = "";
                string xlength = "";
                for (int i=0;i<x.length()-3;i++){
                    print(x[i]);
                    if (int(x[i])%2!=0){
                        odd=odd+1;
                    }
                    xlength=xlength+x[i];
                }
                for (int i=x.length()-3;i<x.length();i++){
                    print(x[i]);
                    if (int(x[i])%2!=0){
                        pairodd=pairodd+1;
                    }
                    tlength=tlength+x[i];

                }
                newl();
                pairodd=pairodd%2;
                odd=odd%2;
                int L=0;
                int R=0;
                print(pairodd);
                print(odd);
                newl();
                if (pairodd==odd){
                   
                } else {
                     ok=2;
                    for (int i=0;i<x.length()-3;i++){
                        int res = int(x[i]-'0');
                        if (int(x[i])%2!=0){
                            if (L==0&&R==0){
                                int current =int(x[0]-'0');
                                int worse = current/2;
                                int better = current-worse;
                                L=1;
                                part1 = part1 + char(better);
                                part2 = part2 + char(worse);
                            } else {
                                if (L==1){
                                    L=0;
                                    R=1;
                                    int current =int(x[0]-'0');
                                    int worse = current/2;
                                    int better = current-worse;
                                    L=1;
                                    part1 = part1 + char(worse);
                                    part2 = part2 + char(better);
                                } else {
                                    L=1;
                                    R=0;
                                    int current =int(x[0]-'0');
                                    int worse = current/2;
                                    int better = current-worse;
                                    L=1;
                                    part1 = part1 + char(better);
                                    part2 = part2 + char(worse);
                                }
                            }
                        } else {

                        }
                    }
                    int res3=int(x[x.length()-3]);
                    int res2=int(x[x.length()-2]);
                    int res1=int(x[x.length()-1]);
                    if (L==0&&R==0){
                        if (x[x.length()-1]=='9'){
                            part1=part1+char(res3/2);
                            part2=part2+char(res3/2);

                            int res4 = 10 + res2;
                            part1=part1+char(res4/2);
                            part2=part2+char(res4)

                            
                        } else {
                            part1
                        }
                    } else {
                        if (x[x.length()-1]=='9'){
                            
                        } else {

                        }
                    }
                    
                    for (int i=x.length()-3;i<x.length();i++){
                        int res = int(x[i]-'0');
                        if (int(x[i])%2!=0){
                            if (L==0&&R==0){
                                int current =int(x[0]-'0');
                                int worse = current/2;
                                int better = current-worse;
                                L=1;
                                part1 = part1 + char(better);
                                part2 = part2 + char(worse);
                            } else {
                                if (L==1){
                                    L=0;
                                    R=1;
                                    int current =int(x[0]-'0');
                                    int worse = current/2;
                                    int better = current-worse;
                                    L=1;
                                    part1 = part1 + char(worse);
                                    part2 = part2 + char(better);
                                } else {
                                    L=1;
                                    R=0;
                                    int current =int(x[0]-'0');
                                    int worse = current/2;
                                    int better = current-worse;
                                    L=1;
                                    part1 = part1 + char(better);
                                    part2 = part2 + char(worse);
                                }
                            }
                        } else {

                        }
                    }
                }
            }

        }
        if (ok==1){
            print(A);print(B);
            newl();
        } else if (ok==2) {
            print(part1);print(part2);
            newl();
        } else {
            print(-1);
        }
    }
    

}