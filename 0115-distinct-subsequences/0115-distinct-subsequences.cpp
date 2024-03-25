class Solution {
// private:
//     int memoisation(string s, string t, int i, int j, vector<vector<int>> &dp){
//         //base case
//         if(j < 0) return 1;
//         if(i < 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i] == t[j]){
//             return dp[i][j] = memoisation(s, t, i-1, j-1, dp) + memoisation(s, t, i-1, j, dp);
//         }
//         else{
//             return dp[i][j] = memoisation(s, t, i-1, j, dp);
//         }
//     }
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> prev(m+1, 0);
        //base case
        prev[0] = 1;
        int MOD = 1e9 + 7;
        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){
                if(s[i-1] == t[j-1]){
                    prev[j] = (prev[j-1] + prev[j])%MOD;
                }
            }
        }
        return prev[m];
    }
};