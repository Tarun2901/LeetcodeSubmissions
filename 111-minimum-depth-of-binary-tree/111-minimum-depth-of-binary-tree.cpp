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
    int minDepth(TreeNode* root) {
        if(root== NULL)
        {
            return 0; 
        }
        int lvl = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0)
        {
            int size = q.size();
               lvl++;
            while(size--)
            {
                TreeNode* node = q.front();
                cout<<node->val<<endl;
                q.pop();
                bool left = false;
                bool right = false;
                if(node->left!=NULL)
                {
                    q.push(node->left);
                    left = true;
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                    right = true;
                }
                if(!left&&!right)
                {
                    return lvl;
                }
            }
         
        }
        
        return lvl;
    }
};