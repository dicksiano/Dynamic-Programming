#include <bits/stdc++.h>
using namespace std;

vector<int> preprocess(vector<int> v) {
    for(int i = 1; i < v.size(); i++) v[i] += v[i-1];
    return v;
}

int dp(int i, int j, vector<int> &freq, vector<int> &s, vector< vector<int> > &memo) {
    if(i > j) return 0;
    if(memo[i][j] != -1) return memo[i][j];

    memo[i][j] = INT_MAX;
    for(int k = i; k <= j; k++) 
        memo[i][j] = min(memo[i][j], dp(i, k-1, freq, s, memo) + dp(k+1, j, freq, s, memo));

    int sum = s[j] - ( (i==0) ? 0 : s[i-1] );
    return memo[i][j] = memo[i][j] + sum; 
}

int obst(vector<int> &freq) {
    int N = freq.size();

    vector<int> s = preprocess(freq);
    vector< vector<int> > memo(N, vector<int>(N, -1));

    return dp(0, N-1, freq, s, memo);
}

int main() {
    int arr[] = {34, 8, 50};
    vector<int> freq(arr, arr + 3);
    cout << obst(freq) << endl;
    return 0;
}