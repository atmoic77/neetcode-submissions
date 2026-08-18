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
    vector<int> rsview;
    queue<TreeNode*> level;
    vector<int> rightSideView(TreeNode* root) {
       if(root == nullptr) return rsview;
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
                int sz = sets.size();
                rsview.push_back(sets[sz-1]);
                result.push_back(sets);
            }
        }
        return rsview;  
    }
};
