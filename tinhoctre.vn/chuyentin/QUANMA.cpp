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

struct vinhuchi {
    int x, y, score;
};

int main() {
    IO("QUANMA");
    FIO();
    int n, m, x1, y1, x2, y2;

    read(n);
    read(m);
    read(x1);
    read(y1);
    read(x2);
    read(y2);

    int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int minScore = 0;

    vector<vector<int>> vist(n + 2, vector<int>(m + 2, 0));

    queue<vinhuchi> check;
    check.push({x1, y1, 0});

    while (!check.empty()) {
        vinhuchi current = check.front();
        check.pop();

        int x = current.x;
        int y = current.y;
        int score = current.score;

        if (x == x2 && y == y2) {
            minScore = score;
            break;
        }

        if (vist[x][y] == 1){
            //print(x);
            //print(y);
            continue;
        } 
        vist[x][y] = 1;

        for (int i = 0; i < 8; i++) {
            int x3 = x + X[i];
            int y3 = y + Y[i];
            if (x3 >= 1 && x3 <= n && y3 >= 1 && y3 <= m && vist[x3][y3] == 0) {
                check.push({x3, y3, score + 1});
            }
        }
    }        
    if (x1 == x2 && y1 == y2) {
        print(0);
    } else if (minScore==0){
        print(-1);
    } else {
        print(minScore);
    }
    

    return 0;
}