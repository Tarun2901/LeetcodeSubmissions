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
    bool res = true;
    
    int solve(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        //Postorder
        if(abs(left-right)>1)
        {
            res = false;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        solve(root);
        return res;
    }
};