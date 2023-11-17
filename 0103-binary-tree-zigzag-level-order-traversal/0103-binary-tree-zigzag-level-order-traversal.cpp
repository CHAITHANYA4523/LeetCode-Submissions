class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans; 
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; 
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                // to decide in which order we need to traverse the nodes
                int index = (leftToRight) ? i:(size-1-i);
                level[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            leftToRight = !leftToRight; // Switching for every level
            ans.push_back(level);
        }
        return ans;
    }
};
