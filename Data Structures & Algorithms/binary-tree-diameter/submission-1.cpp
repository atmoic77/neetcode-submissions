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
    int largestdia = 0;
    int count(TreeNode* root){
    if(root == nullptr) return 0;
    int leftside = count(root -> left);
    int rightside = count(root -> right);
    largestdia = max(largestdia,leftside + rightside);
    return 1 + max(leftside,rightside);
}
    int diameterOfBinaryTree(TreeNode* root) {
      count(root);
      return largestdia;  
    }
};
