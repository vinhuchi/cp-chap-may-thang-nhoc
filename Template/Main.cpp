#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
//Type
using LL = long long;
#define endl "\n"
//Functions
#define IO(value)  freopen(value".inp", "r", stdin);   freopen(value".out", "w", stdout);
#define FIO() ios_base::sync_with_stdio(false); cin.tie(NULL);
=======
const int inf  = 1e9 + 7;
const int maxN = 1e5 + 7;
>>>>>>> 70be2594685318ecc938621681ea15bd6010d2b7

int n, q;
int a[maxN];
int st[4 * maxN]; // Lí do sử dụng kích thước mảng là 4 * maxN sẽ được giải thích ở phần sau

// Thủ tục xây dựng cây phân đoạn
void build(int id, int l, int r) {
    // Đoạn chỉ gồm 1 phần tử, không có nút con
    if (l == r) {
        st[id] = a[l];
        return;
    }

    // Gọi đệ quy để xử lý các nút con của nút id
    int mid = l + r >> 1; // (l + r) / 2
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    
    // Cập nhật lại giá trị min của đoạn [l, r] theo 2 nút con
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

// Thủ tục cập nhật
void update(int id, int l, int r, int i, int val) {
    // i nằm ngoài đoạn [l, r], ta bỏ qua nút id
    if (l > i || r < i) return;
    
    // Đoạn chỉ gồm 1 phần tử, không có nút con
    if (l == r) {
        st[id] = val;
        return;
    }
    
    // Gọi đệ quy để xử lý các nút con của nút id
    int mid = l + r >> 1; // (l + r) / 2
    update(2 * id, l, mid, i, val);
    update(2 * id + 1, mid + 1, r, i, val);
    
    // Cập nhật lại giá trị min của đoạn [l, r] theo 2 nút con
    st[id] = min(st[2 * id], st[2 * id + 1]);
}


// Hàm lấy giá trị
int get(int id, int l, int r, int u, int v) {
    // Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
    if (l >  v || r <  u) return inf; 
    
    /* Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, 
        ta trả lại thông tin lưu ở nút id */
    if (l >= u && r <= v) return st[id];

    // Gọi đệ quy với các nút con của nút id
    int mid = l + r >> 1; // (l + r) / 2
    int get1 = get(2 * id, l, mid, u, v);
    int get2 = get(2 * id + 1, mid + 1, r, u, v);
    
    // Trả ra giá trị nhỏ nhất theo 2 nút con
    return get1+ get2;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);

    // Get q value
    cin >> q;
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) update(1, 1, n, x, y); // Gán giá trị y cho phần tử ở vị trí x 
        else cout << get(1, 1, n, x, y) << '\n'; // In ra giá trị nhỏ nhất trong đoạn [x, y]
    }
}