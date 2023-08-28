//https://oj.vnoi.info/problem/bedao_m16_candy
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int arr[N+5];
    for (int i=0;i<N;i++){
        cin >> arr[i];
    }
    for (int i=N-1;i>0;i--){
        arr[i-1]=arr[i-1]+arr[i]/2;
    }
    cout << arr[0];
    return 0;
}