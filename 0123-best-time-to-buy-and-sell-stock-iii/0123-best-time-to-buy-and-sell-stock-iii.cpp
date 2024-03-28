class Solution {
private:
    int memoisation(vector<int>& prices, int ind, int canBuy,
    vector<vector<vector<int>>> &dp, int transactions){
        if(ind == prices.size()){
            return 0;
        }
        if(transactions == 0){
            return 0; 
        }
        if(dp[ind][canBuy][transactions] != -1) return dp[ind][canBuy][transactions];
        long long profit = 0;
        if(canBuy){
            int buy = -prices[ind] + memoisation(prices, ind+1, 0, dp, transactions);
            int notBuy = memoisation(prices, ind+1, 1, dp, transactions);
            profit = max(buy, notBuy);
        }
        else{
            int sell = prices[ind] + memoisation(prices, ind+1, 1, dp, transactions-1);
            int notSell = memoisation(prices, ind+1, 0, dp, transactions);
            profit = max(sell, notSell);
        }
        return dp[ind][canBuy][transactions] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return memoisation(prices, 0, 1, dp, 2);
    }
};