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
    vector<int> sadvi;
    int findmin(TreeNode* root){
            if(root == nullptr) return 0;
            else{
                findmin(root -> left);
                sadvi.push_back(root -> val);
                findmin(root -> right);
        }
        return sadvi[0];
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root == nullptr) return root;
       if(root -> val == key){
        if(root -> left == nullptr && root -> right == nullptr){
            return nullptr;
        }
        else if(root -> left == nullptr || root -> right == nullptr){
            if(root -> left == nullptr){
                return root -> right;
            }
            return root -> left;
        }
        else{
            int minval = findmin(root -> right);
            root -> val = minval;
            root -> right = deleteNode(root -> right,minval);
            return root;
        }
       }
       else if(root -> val > key){
        root -> left = deleteNode(root -> left,key);
       }
       else{
        root -> right = deleteNode(root -> right,key);
       }
       return root;
    }
};