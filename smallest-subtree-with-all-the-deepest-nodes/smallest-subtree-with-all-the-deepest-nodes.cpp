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
    TreeNode* record = nullptr;
    
    int solve(TreeNode* node,int lvl,int currlvl)
    {
        if(currlvl == lvl-1)
        {
            record = node;
            return 1;
        }
        int lef = 0;
        int rig = 0;
        if(node->left!=nullptr)
        {
           lef = solve(node->left,lvl,currlvl+1);
        }
        if(node->right!=nullptr)
        {
             rig = solve(node->right,lvl,currlvl+1);
        }
        if(lef == 1 && rig == 1)
        {
            record = node;
        }
        if(lef == 1 || rig == 1)
        {
            return 1;
        }
        return 0;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(q.size()>0)
        {
            int size = q.size();
            lvl++;
            while(size-->0)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=nullptr)
                {
                    q.push(temp->left);
                }
                if(temp->right!=nullptr)
                {
                    q.push(temp->right);
                }
            }
        }
        int n = solve(root,lvl,0);
        return record;
    }
};