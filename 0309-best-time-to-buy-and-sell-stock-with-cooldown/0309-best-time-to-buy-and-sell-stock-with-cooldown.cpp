class Solution {
private:
    int memoisation(vector<int>&prices, int ind, int canBuy, vector<vector<int>>& dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        long long profit = 0;
        if(canBuy){
            int buy = -prices[ind] + memoisation(prices, ind+1, 0, dp); 
            int notBuy = 0 + memoisation(prices, ind+1, 1, dp); 
            profit = max(buy, notBuy);
        }
        else{
            int sell = prices[ind] + memoisation(prices, ind+2, 1, dp); 
            int notSell = 0 + memoisation(prices, ind+1, 0, dp); 
            profit = max(sell, notSell);
        }
        return dp[ind][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return memoisation(prices, 0, 1, dp);
    }
};