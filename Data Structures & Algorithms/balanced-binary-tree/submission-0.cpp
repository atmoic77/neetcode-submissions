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

int count(TreeNode* root){
    if(root == nullptr) return 0;
    int leftside = count(root -> left);
    int rightside = count(root -> right);
    return 1 + max(leftside,rightside);
}
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int side1 = count(root -> left);
        int side2 = count(root -> right);
        if(abs(side1 - side2) > 1) return false;
        else{
        bool trueleft = isBalanced(root -> left);
        bool trueright = isBalanced(root -> right);
        return trueleft && trueright;
        }
    }
};
