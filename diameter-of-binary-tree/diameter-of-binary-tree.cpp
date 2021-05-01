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
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        int mx = max(lh,rh);
        return mx+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int ldia = diameterOfBinaryTree(root->left);
        int rdia = diameterOfBinaryTree(root->right);
        int lheight = height(root->left);
        int rheight = height(root->right);
        int ans = lheight+rheight;
        int dia = max(ans,max(ldia,rdia));
        return dia;
    }
};