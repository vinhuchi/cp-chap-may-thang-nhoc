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
    IO("c");
    FIO();
    int n, k, x;
    read(n);
    read(k);
    read(x);


    for (int i=0;i<n;i++){

    }
}