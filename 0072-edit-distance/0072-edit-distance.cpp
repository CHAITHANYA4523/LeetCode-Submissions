class Solution {
private:
    int memoisation(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = memoisation(s1, s2, i-1, j-1, dp);
        }
        else{
            int insertOperation = 1 + memoisation(s1, s2, i, j-1, dp);
            int deleteOperation = 1 + memoisation(s1, s2, i-1, j, dp);
            int replaceOperation = 1 + memoisation(s1, s2, i-1, j-1, dp);
            return dp[i][j] = min(insertOperation, min(deleteOperation, replaceOperation));
        }
    }
public:
    int minDistance(string word1, string word2){
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memoisation(word1, word2, n-1, m-1, dp);
    }
};