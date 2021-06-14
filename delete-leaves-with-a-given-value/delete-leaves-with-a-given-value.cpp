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
    
    TreeNode* travelandchange(TreeNode* root, int target)
    {
        if(root == NULL)
        {
            return NULL;
        }
        root->left = travelandchange(root->left,target);
        root->right = travelandchange(root->right,target);
        //postorder - check node's value and delete if == target
        if(root->val == target && root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        return root;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* node = root;
        TreeNode* ans = travelandchange(node,target);
        return ans;
    }
};