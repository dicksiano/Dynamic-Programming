#include <bits/stdc++.h> 
using namespace std; 

/*
    Burst Ballon

    Time:  O(n^3)
    Space: O(n^2)
*/

int bb(int i, int j, vector<int> &d, vector<vector<int> > &memo) {
    if(i > j) return 0;
    if(memo[i][j] != -1) return memo[i][j];

    for(int k = i; k <= j; k++)
        memo[i][j] = max(memo[i][j], bb(i, k-1, d, memo) + d[i-1] * d[k] * d[j+1] + bb(k+1, j, d, memo));
    return memo[i][j];
}

int burstBallon(vector<int> &d) {
    int N = d.size();
    d.insert(d.begin(), 1); d.push_back(1);

    vector<vector<int> > memo(N+2, vector<int>(N+2, -1));
    return bb(1, N, d, memo);
}

int main() {
    int arr[] = {3,1,5,8};
    vector<int> d(arr, arr + 4);
    cout << burstBallon(d) << endl;
    return 0;
}