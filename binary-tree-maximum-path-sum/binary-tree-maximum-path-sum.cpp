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
    
    int mx = INT_MIN;
    
    int solve(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        mx = max(mx,max(max(root->val,root->val+left),max(root->val+right,root->val+right+left)));
        return max(root->val,max(root->val+left,root->val+right));
    }
    int maxPathSum(TreeNode* root) {   
        int ans = solve(root);
        return mx;
    }
};