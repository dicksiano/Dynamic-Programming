#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX-1); 
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) 
        for(int j = 0; j < coins.size(); j++) 
            if(i >= coins[j]) dp[i] = min(dp[i], 1 + dp[ i- coins[j] ]);
    for(int x : dp) cout << x << endl;
    return (dp[amount] == INT_MAX-1 ? -1 : dp[amount]);
}

int main() {
    int arr[] = {1, 3, 4, 5};
    vector<int> coins(arr, arr+4);
    int value = 10;
            
    cout << "coinChange: " << coinChange(coins, value) <<  endl;
    return 0;
}