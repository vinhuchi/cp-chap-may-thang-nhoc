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
int st[4*100005];
int arr[100005];
int stored[100005];
int n;
void build(int id, int l, int r){
    if (l==r){
        st[id]=arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=st[id*2]+st[id*2+1];
}
void update(int id, int l, int r, int i, int v){
    if (l > i  && r < i){
        return;
    }
    if (l==r){
        st[id]=v;
        return;
    }
    int mid = l + r >> 1;
    st[id] = st[2 * id]+ st[2 * id + 1];
}
int get(int id, int l, int r, int u, int v){
    if (l > v || r < u){
        return 0;
    }
    if (l >= u && r <= v){
        return st[id];
    }
    int mid = l + r >> 1;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int main() {
    //IO("DCB");
    FIO();
    read(n);
    for (int i=1;i<=n;i++){
        read(arr[i]);
    }
    build(1,1,n);
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if (get(1,1,n,i,j)==0){
                for (int k=i;k<=j;k++){
                    stored[k]=stored[k]+1;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        print(stored[i]);
    }
}