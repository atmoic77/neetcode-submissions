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
    vector<int> pooja;
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        else{
            inorder(root -> left);
            pooja.push_back(root -> val);
            inorder(root -> right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return pooja[k-1];
    }
};
