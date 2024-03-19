class Solution {
private:
    int memoisation(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp){
        //when any one string goes out of bounds return 0 (no matching)
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }
        //overlapping case
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        //if both characters are matching add to the subsequence
        if(text1[ind1] == text2[ind2]){
            return dp[ind1][ind2] = 1 + memoisation(text1, text2, ind1-1, ind2-1, dp);
        }
        //if not matching check for both cases
        //1 is not added as characters not matched
        return dp[ind1][ind2] = max(memoisation(text1, text2, ind1-1, ind2, dp),
        memoisation(text1, text2, ind1, ind2-1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memoisation(text1, text2, n-1, m-1, dp);
    }
};