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
    //IO("NGOAC797");
    FIO();
    int t;
    read(t);
    map<char,int> m;
    m['(']=1;
    m[')']=-1;

    m['[']=2;
    m[']']=-2;

    m['{']=3;
    m['}']=-3;

    while (t--) {
        stack<char> s;
        while (!s.empty()){
            s.pop();
        }
        string str;
        read(str);
        int n = str.length();
        int flag = false;
        for (int i=0;i<n;i++){
            if (m[str[i]]>0){

                s.push(str[i]);
               // print(str[i]);
            } else {
                //print(str[i]);
                if (s.empty()){
                    flag=true;
                    //printl(0);
                    //print("OK None")
                    break;

                } else if (m[s.top()]+m[str[i]]==0){
                    //print("OK Pass")
                    s.pop();

                } else {
                     //print("OK Not Pass")
                    //printl(0);
                    break;

                }

            }
            
        }
        if (s.empty()) {
            if (flag){
                
                printl(0);
            } else {
printl(1);
            }
           
        } else{
            printl(0);
        } 
            
    }
    
}