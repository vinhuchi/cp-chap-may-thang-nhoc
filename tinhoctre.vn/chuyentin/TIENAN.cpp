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

const int inf  = 1e9 + 7;
const int maxN = 1e5 + 7;

int n, q;
int a[maxN];
int st[4 * maxN]; // Lí do sử dụng kích thước mảng là 4 * maxN sẽ được giải thích ở phần sau
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    int mid = l + r >> 1; // (l + r) / 2
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

void update(int id, int l, int r, int i, int val) {
    if (l > i || r < i) return;
    
    if (l == r) {
        st[id] = val;
        return;
    }
    
    int mid = l + r >> 1; // (l + r) / 2
    update(2 * id, l, mid, i, val);
    update(2 * id + 1, mid + 1, r, i, val);
    
    st[id] = min(st[2 * id], st[2 * id + 1]);
}


int get(int id, int l, int r, int u, int v) {
    if (l >  v || r <  u) return inf; 
    
    if (l >= u && r <= v) return st[id];

    int mid = l + r >> 1; // (l + r) / 2
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    
    return min(get1, get2);
}
int main() {
    //IO("TIENAN");
    FIO();
    int t;
    read(t);
    
    while (t--) {
        int sum = 0;
        //a[maxN];
        int d;
        read(d); 
        loop(i,1,d+1){
            read(a[i]);
        }
        build(1, 1, d);
        int continious = d;
        sum = d* get(1,1,d,1,d);
        int rmax = d* get(1,1,d,1,d);
        int maxx=d* get(1,1,d,1,d);
        int l =1;
        
        int r= d;
        map<int,vector<pair<int,int>>> vinhuchi{};
        int c=0;
        int c2=false;
        vinhuchi[rmax].push_back(make_pair(l,r));

        while (r>l){
            //print("Again");
            int before=l+1;
            int after=r-1;
            int range = r-l;

            int sum1 =  range* get(1,1,d,before,r); 
            int sum2 = range * get(1,1,d,l,after); // add the current element so you always compute average of `x` elements.
            if (sum1>sum2){
                l++;
                vinhuchi[sum1].push_back(make_pair(before,r));
            } else if (sum1==sum2)
            { 
                int copy1 =before+1;
                int copy2 =after-1;
                int currentsum = sum1;
                int range2 = range-1;
                while (sum1==sum2&& range2>0){
                    
                    sum1 =  range2* get(1,1,d,copy1,r); 
                    copy1++;

                    sum2 = range2 * get(1,1,d,l,copy2); // add the current element so you always compute average of `x` elements.
                    copy2--;
                    range2=range2-1;
                    //print(range2);

                    maxx = max( sum1, sum2 ); //maximize max
                    if (maxx>rmax){
                        if (sum1>sum2){
                            vinhuchi[sum1].push_back(make_pair(copy1-1,r));
                        } else if (sum1<sum2) {
                            vinhuchi[sum2].push_back(make_pair(l,copy2+1));
                        }
                    }

                    rmax = max(maxx,rmax);
                }
               // print(copy1)
                //print(copy2)
                //print(sum1);
               // print(sum2);
                //newl();
                
                if (sum1>sum2){
                    l=copy1;
                    vinhuchi[sum1].push_back(make_pair(copy1-1,r));
                } else if (sum1<sum2) {
                    r=copy2;
                    vinhuchi[sum2].push_back(make_pair(l,copy2+1));
                } else {
                    l=r;
                }
                
                maxx = max( sum1, sum2 ); //maximize max
                rmax = max(maxx,rmax);
            } else {
                
            
                r--;
                //print(l);
                //print(after);
                //print(range);
                //print(a[1]);
                //print(get(1,1,d,l,after));
                //print("------- ");
                vinhuchi[sum2].push_back(make_pair(l,after));
            }
            
            maxx = max( sum1, sum2 ); //maximize max
            rmax = max(maxx,rmax);

            //if (maxx<=rmax){
            //    if (!c2){
            //        vinhuchi[maxx].push_back(make_pair(l,r));
            //        c2 = true;
            //    } 
            //} else {
            //    c2=false;
            //}
            //print(sum1);
            //print(sum2);
            //printl(rmax);
            //continious=continious-1;
        }
        print(rmax);
        int besti = d;
        pair<int,int> bestpair;
        for (const auto &pair : vinhuchi[rmax]) {
            int i = pair.first;  // Get the first element of the pair (the 'i' value)
            int j = pair.second; // Get the second element of the pair (the 'j' value)
            if (i<besti){
                besti=i;
                bestpair=pair;
            }
            // Print the pair elements (i and j)
        }
        cout << bestpair.first << " " << bestpair.second;
        newl();

    }
    
    
}