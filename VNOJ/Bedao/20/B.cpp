#include <bits/stdc++.h>

using namespace std;
using LL = long long;
#define endl "\n"
#define FileName (std::string(__FILE__).substr(0, std::string(__FILE__).find_last_of(".")))
#define IOF() freopen((FileName + ".inp").c_str(), "r", stdin); freopen((FileName + ".out").c_str(), "w", stdout);

const int inf  = 1e9 + 7;
const int maxN = 1e5 + 7;

int n, q;
int a[maxN];
int st[4 * maxN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    
    st[id] = st[2 * id] + st[2 * id + 1];
}

void update(int id, int l, int r, int i, int val,int toxors) {
    if (l > i || r < i) return;
    
    if (l == r) {
        st[id] = val;
        return;
    }
    
    int mid = l + r >> 1;
    update(2 * id, l, mid, i, val,toxors);
    update(2 * id + 1, mid + 1, r, i, val,toxors);
    
    st[id] = ((st[2 * id]^toxors) ^ (st[2 * id + 1]^toxors));
}

int get(int id, int l, int r, int u, int v) {
    if (l >  v || r <  u) return inf; 
    
    if (l >= u && r <= v) return st[id];

    int mid = l + r >> 1;
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);

    return get1 ^ get2;
}

int main() {
    //IOF();
    cin >> n;
    cin >> q;
    int arr[n+5]{0};
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            int toxor;
            cin >> toxor;
            for (int i=x-1;i<y;i++){
                arr[i]=arr[i]^toxor;
                //cout << arr[i] << " ";
                //cout << endl;
            }
        } else {
            int res=arr[x-1];
            for (int i=0;i<n;i++){
                if (i>=x && i < y){
                    res=res^arr[i];
                }
                arr[i]=0;
            }
            cout << res << endl;
        }
    }
}