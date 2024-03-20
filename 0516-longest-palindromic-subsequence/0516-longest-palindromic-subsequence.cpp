class Solution {
private:
    int memoisation(string &s, int low, int high, vector<vector<int>> &dp){
        //if low and high cross each other
        if(low > high){
            return 0;
        }
        if(dp[low][high] != -1) return dp[low][high];
        //only one char is considered in longestPalindromeSubseq
        if(low == high){
            return 1;
        }
        //add 2 (both character are part of palindromic subsequence) to 
        //the count and check for next character match
        if(s[low] == s[high]){
            return dp[low][high] = 2 + memoisation(s, low+1, high-1, dp);
        }
        else{
            return dp[low][high] = max(memoisation(s, low+1, high, dp),
            memoisation(s, low, high-1, dp));
        }
    }
public:
    int longestPalindromeSubseq(string s){
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memoisation(s, 0, n-1, dp);
    }
};