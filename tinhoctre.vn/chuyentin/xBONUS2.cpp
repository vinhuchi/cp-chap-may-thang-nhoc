#include <bits/stdc++.h>
using namespace std;
#define IO(value) freopen(value".inp", "r", stdin); freopen(value".out", "w", stdout);
#define FIO()        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define loop(x, start, end) for (int x = start; x < end; x++)
#define loop2(x, start, end) for (int x = end - 1; x >= start; x--)
#define newl() cout << "\n";
#define read(x) cin >> x
#define print(x) cout << x << " ";
int main() {
    //IO("xBONUS2");
    LL x[1100000],y[1100000];
    FIO();
    int n,k;
    read(n);
    read(k);
    loop(i,0,k){
        long long p1,p2,pt;
        read(p1);
        read(p2);
        read(pt);
       // print(pt);
        x[p1-1][p2-1]=pt;
    }
    int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    long long maxScore=0;
    //loop(k,0,x){
        //loop(h,0,x){
            //print(arr[k][h]);
        //}
        //newl();
    //}
    loop(i,0,k){
        if (arr[k][h]!=0) continue;
        long long cur = 0;
        for (int i=0;i<8;i++){
            int x1=k+X[i];
            int y1=h+Y[i];
            if (x1>=0 && x1<x && y1>=0 && y1<x){
                //print(x1);
                //print(y1);
                //print(arr[x1][y1]);
                cur=cur+arr[x1][y1];
                
            }
            
        }
        //newl()
        maxScore=max(maxScore,cur);
        //print(maxScore);
        
    }
    print(maxScore);
    //print((maxX+1)*(maxY+1));
}