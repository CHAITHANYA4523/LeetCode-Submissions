class Solution {
private:
    int minNoOfCoins(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp){
        if(ind == 0){
            if(amount%coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }
        int notPickAndMove = 0 + minNoOfCoins(coins, amount, ind-1, dp);
        int pickAndStay = 1e9;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        if(coins[ind] <= amount){
            pickAndStay = 1 + minNoOfCoins(coins, amount-coins[ind], ind, dp);
        }
        return dp[ind][amount] = min(pickAndStay, notPickAndMove);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = minNoOfCoins(coins, amount, n-1, dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};