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
    vector<vector<int>> result;
    
    queue<TreeNode*> level;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return result;
        else{
            level.push(root);
            while(!level.empty()){
                vector<int> sets;
                int z = level.size();
                for(int i = 0;i < z;i++){
                    TreeNode* current = level.front();
                    level.pop();
                    if(current -> left != nullptr) 
                    level.push(current -> left);
                    if(current -> right != nullptr) 
                    level.push(current -> right);
                    sets.push_back(current -> val);
                    
                }
                result.push_back(sets);
            }
        }
        return result;
    }
};
