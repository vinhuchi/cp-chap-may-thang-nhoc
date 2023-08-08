#include <iostream>
#include <vector>
#include <climits>
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
int N, M;
vector<vector<int>> path(1005, vector<int>(1005)); // Fix the declaration of grid
int ans = INT_MAX;
string best = "";
void find(int x, int y, string duongdi, int val) {
    if (x == N && y == M) {
        int check=0;
        int count = val;
        if (count % 10 == 0) check++;;

        while (count > 0) {
            if (count % 10 == 0) check++;;
            
            count /= 10;
        }        

        if (check < ans) {
            ans = check;
            best = duongdi;
        }
        return;
    }
    int newx =x + 1;
    int newy =y + 1;
    if (newy<= M) {
        find(x,newy,duongdi+"L",val * path[x][newy]);
    }
    if (newx<=N) {
        find(newx,y,duongdi+"D",val * path[newx][y]);
    }
}

int main() {
    IO("DUONGDI");
    cin >> N >> M;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            cin >> path[i][j];
        }
    }

    find(1, 1, "", path[1][1]);
    print(ans);
    newl();
    print(best);
}