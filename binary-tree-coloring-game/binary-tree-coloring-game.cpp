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
    bool lb = false;
    
    int solve(TreeNode* root,int n,int x)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = solve(root->left,n,x);
        int right = solve(root->right,n,x);
        
        if(root->val == x)
        {
            int mx = max(n-left-right-1,max(left,right));
            if(mx>n/2)
            {
                lb = true;
            }
        }
        return 1+left+right;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int ans = solve(root,n,x);
        return lb;
    }
};