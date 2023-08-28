// A dynamic programming based
// solution for 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;
 
// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int> > K(n + 1, vector<int>(W + 1));
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(1
                                  + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
 
// Driver Code
int main()
{
    int n,m;
    cin >> n >> m;
    int weight[n+5] ;
    for (int i=0;i<n;i++) {
        cin >> weight[i];
        if 
    }
    int profit[] = { 60, 100, 120 };
    for (int j=0;j<m;j++){
        int W;
        cin >> W;
        cout << knapSack(W, weight, profit, n);

    }
 
    return 0;
}