/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* find(TreeNode* root,int data)
    {
        if(root == NULL)
        {
            return nullptr;
        }
        if(root->val == data)
        {
            return root;
        }
        
       TreeNode* lfind =  find(root->left,data);
       TreeNode* rfind =  find(root->right,data);
        
        if(lfind!=NULL)
        {
            return lfind;
        }
        if(rfind!=NULL)
        {
            return rfind;
        }
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
       
            int val = target->val;
            return find(cloned,val);
          
    }
};