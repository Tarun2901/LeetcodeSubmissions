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
    vector<TreeNode*>v;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        for(int i = 0;i<v.size()-1;i++)
        {
            v[i]->left = nullptr;
            v[i]->right = v[i+1];
        }
        v[v.size()-1]->left = nullptr;
         v[v.size()-1]->right = nullptr;
        return v[0];
    }
};