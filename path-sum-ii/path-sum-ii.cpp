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
    vector<vector<int>> ans;
    
    
    void travelandfill(TreeNode* root, int target,vector<int>& temp)
    {   
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            if(target == root->val)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            
            return;
        }
        temp.push_back(root->val);
       
        target = target-root->val;
        travelandfill(root->left,target,temp);
        travelandfill(root->right,target,temp);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<int> temp;
            travelandfill(root,targetSum,temp);
            return ans;
    }
};