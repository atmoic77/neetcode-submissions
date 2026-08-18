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

    bool isSameTree(TreeNode* root,TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr || subRoot == nullptr) return false;
        if(root -> val != subRoot -> val) return false;
        bool ls = isSameTree(root -> left,subRoot -> left);
        bool rs = isSameTree(root -> right,subRoot -> right);
        return ls && rs;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(isSameTree(root,subRoot)) return true;
        bool lh = isSubtree(root -> left,subRoot);
        bool rh = isSubtree(root -> right,subRoot);
        return lh || rh;
    }
};
