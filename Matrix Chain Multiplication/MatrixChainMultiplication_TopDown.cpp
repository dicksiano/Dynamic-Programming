#include <bits/stdc++.h> 
using namespace std; 

/*
    Matrix Chain Multiplication

    Time:  O(n^3)
    Space: O(n^2)
*/

int mcm(int i, int j, vector<int> &d, vector<vector<int> > &memo) {
    if(i > j) return 0;
    if(memo[i][j] != -1) return memo[i][j];

    memo[i][j] = INT_MAX;
    for(int k = i; k <= j; k++)
        memo[i][j] = min(memo[i][j], mcm(i, k-1, d, memo) + d[i-1] * d[k] * d[j+1] + mcm(k+1, j, d, memo));
    return memo[i][j];
}

int mcm(vector<int> &d) {
    int N = d.size();

    vector<vector<int> > memo(N+1, vector<int>(N+1, -1));
    return mcm(1, N-2, d, memo);
}

int main() {
    int arr[] = {10,30,5,60};
    vector<int> d(arr, arr + 4);
    cout << mcm(d) << endl;
    return 0;
}