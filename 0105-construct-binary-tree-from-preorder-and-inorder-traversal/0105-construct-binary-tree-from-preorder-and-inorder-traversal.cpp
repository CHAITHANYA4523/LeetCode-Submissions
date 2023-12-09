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
    unordered_map<int, int> inMap; // Hash map to store positions of elements in inorder vector
    // pass index by reference to keep it's updated value
    TreeNode* solve(vector<int>& pre, vector<int>& in, int &index, int inOrderStart, int inOrderLast){
        if(index >= pre.size() || inOrderStart > inOrderLast){
            return NULL;
        }
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        // Find the position of the current element in inorder vector using the map
        int position = inMap[element];

        // Recursively build the left and right subtrees
        root->left = solve(pre, in, index, inOrderStart, position-1);
        root->right = solve(pre, in, index, position+1, inOrderLast);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        // Fill the map with positions of elements in inorder vector
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        return solve(preorder, inorder, preOrderIndex, 0, inorder.size()-1);
    }
};
