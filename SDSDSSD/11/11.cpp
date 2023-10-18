#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n+5];
    int res=0;
    int pos=0;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i = 0; i <= n-k; i++) {
        int sum = accumulate(a+i, a+i+k, 0);
        if (res<=sum){
            pos = i;
            res = sum;
        }
        
    }
    cout << res << endl;
    for (int i = pos + 1; i <= pos + k; i++) {
        cout << i << " ";
    }
    return 0;
}