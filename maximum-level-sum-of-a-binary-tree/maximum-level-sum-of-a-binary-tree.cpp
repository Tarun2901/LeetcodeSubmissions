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
    
    
    
    int maxLevelSum(TreeNode* root) {
        
        int maxsum = INT_MIN;
        int mx = 0;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while(q.size()>0)
        {
            int size = q.size();
            int lvlsum = 0;
            while(size-->0)
            {
                TreeNode* node = q.front();
                q.pop();
                lvlsum+= node->val;
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            if(maxsum<lvlsum)
            {
                maxsum = lvlsum;
                mx = lvl;
            }
            lvl++;
        }
        return mx;
    }
};