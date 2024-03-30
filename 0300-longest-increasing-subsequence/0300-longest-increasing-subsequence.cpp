class Solution {
private:
    int memoisation(vector<int> &nums, int ind, int prevInd, vector<vector<int>> &dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        int notPick = 0 + memoisation(nums, ind+1, prevInd, dp);
        int pick = -1e9;
        //we can pick if it is first index or current element value is 
        //larger than previously picked value
        if(prevInd == -1 || nums[ind] > nums[prevInd]){
            pick = 1 + memoisation(nums, ind+1, ind, dp);
        }
        return dp[ind][prevInd+1] = max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //coordinate shift of prevIndex to handle -1 index value
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return memoisation(nums, 0, -1, dp);
    }
};