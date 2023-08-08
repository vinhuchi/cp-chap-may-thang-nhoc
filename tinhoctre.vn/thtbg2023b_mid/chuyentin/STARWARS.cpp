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
int matrix[1005][1005];
int N,M,Q;
int RemoveIsland(int x,int y,int count){
    if (matrix[x][y]==1){
        
        count++;
        matrix[x][y]=0;
        
        if (x-1>=0 ){
            
            //newl();
            count = RemoveIsland(x-1,y,count);
        }
        if (x+1<N){
            count = RemoveIsland(x+1,y,count);
        }
        if (y-1>=0){

            count = RemoveIsland(x,y-1,count);
        }
        if (y+1<M){
            count = RemoveIsland(x,y+1,count);
        }

    }
    return count;
}
int main() {
    //IO("STARWARS");
    FIO();
    
    read(N);
    read(M);
    read(Q);
    int Island = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            read(matrix[i][j]);
            if (matrix[i][j]==1){
                Island++;
            }
        }
    }
    while (Q--){
        int x,y;
        read(x);
        read(y);
        Island = Island - RemoveIsland(x-1,y-1,0);
        print(Island);
        newl();
    }
    //print((maxX+1)*(maxY+1));
}