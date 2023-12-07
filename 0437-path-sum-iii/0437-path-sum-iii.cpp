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
    void dfs(TreeNode* root, long long targetSum, long long sum, int &totalPaths){
        if(root == NULL) return;
        sum += root->val;
        if(sum == targetSum){
            totalPaths++;
        }
        dfs(root->left, targetSum, sum, totalPaths);
        dfs(root->right, targetSum, sum, totalPaths);
    }
    void noOfPossiblePaths(TreeNode* root, long long targetSum, long long sum, int &totalPaths){
        if(root == NULL) return;
        dfs(root, targetSum, sum, totalPaths);
        noOfPossiblePaths(root->left, targetSum, 0, totalPaths);
        noOfPossiblePaths(root->right, targetSum, 0, totalPaths);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int totalPaths = 0;
        noOfPossiblePaths(root, targetSum, 0, totalPaths);
        return totalPaths;
    }
};