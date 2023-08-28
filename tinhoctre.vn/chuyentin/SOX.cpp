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
int xL=1e5,xR=1e5,yR=1e5,yL=1e5;
int main() {
    //IO("SOX");
    FIO();
    int x,y;
    read(x);
    read(y);

    char stephalf[4]={'C','A','B','B'};
    char stepother[2] = {'C','A'};
    char stepother2[2] = {'A','C'};

    int moddiv = x%6;
    if (moddiv == 0){
        int maxcheck = x/6;
        int check1 = 4;
        int check2 = 2;
        if (y < maxcheck*check2) {
            if (y%check2==0){
                print('C');
            } else {
                print('A');
            }
        } else {
            print(stephalf[y%4]);
        }
    } else {
        int disputerange=x/6;
        int L = disputerange*4;
        int R = disputerange*2;
        if (y <= L){
            print(stephalf[y%4]);

        } else if (y >= R){
            if (x%2==0){
                print(stepother[y%2]);
            } else {
                print(stepother2[y%2]);
            }
            
        } else {
            if (x-(R+L)==1){
                print('A');
            } else if (x-(R+L)==2) {
                char tcase[2] = {'A','B'};
                print(tcase[abs(L-y)]);
            } else if (x-(R+L)==3) {
                char tcase[3] = {'A','B','C'};
                print(tcase[abs(L-y)]);
            } else if (x-(R+L)==4) {
                char tcase[4] = {'A','B','A','C'};
                print(tcase[abs(L-y)]);
            } else if (x-(R+L)==5) {
                char tcase[5] = {'A','B','B','A','C'};
                print(tcase[abs(L-y)]);
            }
        }
    }
    //print((maxX+1)*(maxY+1));
}