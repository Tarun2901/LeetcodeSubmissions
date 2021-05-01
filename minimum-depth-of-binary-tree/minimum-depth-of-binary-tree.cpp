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
    int helper(TreeNode* root)
    {
         if(root == NULL)
        {
            return INT_MAX;
        }
        if(root->right== NULL && root->left == NULL)
        {
            return 1;
        }
        int ldepth = helper(root->left);
        int rdepth = helper(root->right);
        return min(ldepth,rdepth)+1;
    }
    int minDepth(TreeNode* root) {
        int k = helper(root);
        if(k == INT_MAX)
        {
            return 0;
        }
        else
        {
            return k;
        }
    }
};