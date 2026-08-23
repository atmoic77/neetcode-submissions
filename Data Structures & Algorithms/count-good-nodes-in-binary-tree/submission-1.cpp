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
    
    void helper(TreeNode* root,int maxval){
        if(root == nullptr) return;
        if(root -> val >= maxval){
            count++;
        }
        maxval = max(maxval,root -> val);
        helper(root -> left,maxval);
        helper(root -> right,maxval);
    }
    int maxval = INT_MIN;
    int count = 0;
    int goodNodes(TreeNode* root) {    
        helper(root,maxval);
        return count;
    }
};
