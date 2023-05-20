#include <bits/stdc++.h>
using namespace std;
#define loop(x, start, end) for(int x=start; x < end; x++)
#define print(x) cout << x << " ";
#define printl(x) cout << x << endl;
#define unpack(arr, start, end) loop(x, start, end){print(arr[x]) } 
int main(){
    loop(i,1,10){
        printl(i);
    }
    int a[5] ={1,2};
    unpack(a,0,5);
}