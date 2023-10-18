#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, D;
    cin >> N >> D;

    vector<string> vinhuchi(N+5);
    for (int i = 0; i < N; i++) {
        cin >> vinhuchi[i];
    }
        
    string Final = "";
    for (int i = 1; i <= D; i++) {
        bool f = true;
        for (int v = 0; v < N; v++) {
            if (vinhuchi[v][i-1] == 'x') {
                f = false;
                break;
            }
        }
        if (f) {
           Final = Final + 'o';
        } else {
            Final = Final + 'x';
        }
    }
    int maxtime = 0;
    int current = 0;
    for (int i = 0; i < D; i++) {
        if (Final[i]=='o'){
            current=current+1;
        } else {
            current=0;
        }
        maxtime=max(maxtime,current);
    }
    cout << maxtime;
    return 0;
}