/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long ans = 0, sum;
    unordered_map<long long,long long> visited;
    void dfs(TreeNode* &root, long long currentSum){
        currentSum += root->val;
        // checking if we already found an interval summing up to that
        ans += visited[currentSum - sum];
        visited[currentSum]++;
        if (root->left) dfs(root->left, currentSum);
        if (root->right) dfs(root->right, currentSum);
        // clearing visited of the last value, for backtracking purposes
        visited[currentSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        // visited set with initial value 0 will help us match from the root
        visited[0] = 1;
        if(root == NULL) return ans;
        dfs(root, 0);
        return ans;
    }
};