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
int maxsum = INT_MIN;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int lh = max(0,dfs(root -> left));
        int rh = max(0,dfs(root -> right));
        maxsum = max(maxsum,lh + rh + root -> val);
        return root -> val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
};
