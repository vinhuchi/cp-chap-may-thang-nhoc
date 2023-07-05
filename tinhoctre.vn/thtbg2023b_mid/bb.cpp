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
    //IO("b");
    FIO();
    map<int, int> goodprice, badprice;
    int N, M;
    read(N);
    read(M);
    int start[N + 5];
    int end[N + 5];
    for (int i = 0; i < N; i++) {
        read(start[i]);
    }
    for (int i = 0; i < N; i++) {
        read(end[i]);
    }
    for (int i = 0; i < N; i++) {
        int res = end[i] - start[i];
        if (res >= 0) {
            goodprice[res]++;
        } else {
            badprice[res]++;
        }
    }
    int rcount = 0;
    LL rprice = 0;
    for (auto x : goodprice) {
        rprice = rprice + (x.I) * x.V;
        rcount = rcount + x.V;
    }
    // Calculate prefix sum for bad items
    vector<pair<int, int>> BP;
    for (auto it = badprice.rbegin(); it != badprice.rend(); it++) {
        BP.push_back(*it);
    }

    // Calculate prefix sum for bad items
    vector<pair<LL, int>> PS;
    PS.push_back({0, 0});

    for (auto it : BP) {

        for (int i=0;i< it.second;i++){
            PS.push_back({abs(PS.back().first) + abs(it.first), PS.back().second + 1});
        }
    }

    loop(_, 0, M) {
        LL concurentmoney;
        read(concurentmoney);
        concurentmoney = concurentmoney + rprice;
        int c = rcount;

        int low = 0, high = PS.size() - 1;

        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (PS[mid].first <= concurentmoney) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        c += PS[low].second;
        
        print(c);
        newl();
    }
}