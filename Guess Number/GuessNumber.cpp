int dp(int i, int j, vector<vector<int> >& memo) {
	if(i >= j) return 0;
        if(memo[i-1][j-1] >= 0) return memo[i-1][j-1];
        
        int c = INT_MAX;
        for(int k = (i+j)/2; k <= j; k++)
            c = min(c, k + max(dp(i, k-1, memo), dp(k+1, j, memo)) );
        
        return memo[i-1][j-1] = c;
}
    
int getMoneyAmount(int n) {
        vector<vector<int> > memo(n, vector<int>(n, -1));
        return dp(1, n,  memo);        
}
