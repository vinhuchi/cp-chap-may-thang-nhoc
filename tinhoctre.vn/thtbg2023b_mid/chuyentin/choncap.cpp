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

int SumDigit(int x, int limit){
    int sum = 0;
    //print(x);
    while (x != 0) {
        if (x % 10>limit){
           // print("Limit exceed")
            return -1;
        }
        //print(x % 10);
       // newl();
        sum = sum + x % 10;
        x = x / 10;
    }
    return sum;
}
int main() {
    //IO("b");
    FIO();
    int s, d, m;
    read(s);
    read(d);
    read(m);
    
    if (s%2==1 || s < m){
        print(-1);
    } else {
        int R=(s/m);
       // if (s%m==0 && R%2==0){
           // for (int i=0;i<R;i++){
            //    cout << m;
           // }
        //} else {
        if (m==1){
            int remain = s;
            string vinhuchi = "";
           // print(lastdivider);
            while (remain>0){
                //print(remain);
                //newl();
                int remamining = min(d*2,remain);
                if (remain/2==remamining && d*2 != remain/2 ){
                    remain=0;
                } else {
                    remain=remain-remamining;
                }
                
                
                //print(remamining);
                vinhuchi= to_string(remamining/2) + vinhuchi;
                vinhuchi= to_string(remamining/2) + vinhuchi ;
                
                

            }
            print(vinhuchi);
        } else if (m==3  || m == 9){
            //print(s%m);
            int count = 0;
            if (s%m==0){
                int remain = s;
                string vinhuchi = "";
            // print(lastdivider);
                while (remain>0){
                    //print(remain);
                    //newl();
                    int remamining = min(d*2,remain);
                    if (remain/2==remamining && d*2 != remain/2){
                        //print("Flagged");
                        //print(remain)
                        remain=0;
                    } else {
                        remain=remain-remamining;
                    }
                    
                    
                    //print(remamining);
                    count=count+2;
                    vinhuchi= to_string(remamining/2)+vinhuchi;
                    vinhuchi= to_string(remamining/2)+vinhuchi;
                    
                    

                }
                print(vinhuchi.size());
                print(vinhuchi);
                
            } else {
                print(-1);
            }
            
        } else if (m==2 || m == 6){
            //print("OK");
            if (s%m!=0){
                print(-1);
            } else {
                int remain = s;
                string vinhuchi = "";
                int lastdivider = 0;
                if (d%2==0){
                    lastdivider=d;
                } else {
                    lastdivider=d-1;
                }
                //print("Divider: ");
                //print(lastdivider);
                //newl();
                while (remain!=0){

                    
                    int remamining = d*2;
                    if (remain>lastdivider*2){
                        //print("Better Than Divider")
                        remain=remain-remamining;
                        if (remain<=lastdivider*2 && ((remain/2)%2!=0 || remain==0)){
                            //print("Enough");
                            remain=remain+2;
                            remamining=remamining-2;
                            if (remain==2){
                                remain=remain+2;
                                remamining=remamining-2;
                            }
                        }
                        
                        
                        vinhuchi= to_string(remamining/2)+ vinhuchi;
                        vinhuchi= to_string(remamining/2) + vinhuchi ;
                        //print(remamining);
                        //print(vinhuchi);
                        //newl();
                    } else {
                        //
                        //print("Missing");
                        //print(remain/2);
                        vinhuchi= vinhuchi + to_string(remain/2);
                        //print(vinhuchi);
                        string vinhuchinew = "";
                        int pushed = false;
                        for (int i=0;i<vinhuchi.size();i++){
                            if (!pushed && (vinhuchi[i]-'0')>remain/2){
                                vinhuchinew=vinhuchinew+to_string(remain/2);
                                vinhuchinew=vinhuchinew+vinhuchi[i];
                                pushed=true;
                            } else {
                                vinhuchinew = vinhuchinew +vinhuchi[i];
                            }
                        }
                        if (pushed==false){
                            vinhuchinew=vinhuchinew+to_string(remain/2);
                        }
                        vinhuchi= vinhuchinew;
                        remain=0;
                    }
                    

                }
                print(vinhuchi);
            }
        } else if (m==5){
            if (s-m*2<0){
                print(-1);
            } else {
                int remain = s-10;
                string vinhuchi = "5";
                int need=true;
                if (d<5){
                    need=false;
                    vinhuchi=vinhuchi+"5";
                }
            // print(lastdivider);
                while (remain>0){
                    //print(remain);
                    //newl();
                    int remamining = min(d*2,remain);
                    if (remain/2==remamining && d*2 != remain/2 ){
                        remain=0;
                    } else {
                        remain=remain-remamining;
                    }
                    
                    
                    //print(remamining);
                    if (remamining/2<5 &&need==true){
                        need=false;
                        vinhuchi= to_string(5) + vinhuchi;
                    }
                    vinhuchi= to_string(remamining/2) + vinhuchi;
                    vinhuchi= to_string(remamining/2) + vinhuchi ;
                    
                    

                }
                if (need==true){
                    vinhuchi= to_string(5) + vinhuchi;
                }
                print(vinhuchi);
            }
        }
        else  {
            int res;
            int pass = 0;
            int res2;
            for (int i=2;i<10;i++){
                
                int canmod=s%i;
                //print("Current Value Mod");
                //print(i);
                //print("Current Can Mod");
                //print(canmod);
                //newl();
                
                if (canmod==0){
                    int total = SumDigit(i*m,d);
                    if (total!=-1 && s%total==0){
                        //print("Passed");
                        res2=i*m;
                        res=s/total;
                        pass=1;
                        break;
                    }
                }
            }
            if (pass){
                for (int i=0;i<res;i++){
                    cout << res2;
                }
            } else {
                cout << -1;
            }
        }
            
        //}
    }
    
}