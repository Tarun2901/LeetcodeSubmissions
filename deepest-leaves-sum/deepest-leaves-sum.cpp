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
    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0)
        {   depth++;
            int size = q.size();
            while(size-->0)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=nullptr)
                {
                    q.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    q.push(node->right);
                }
            }
        }
       int ans = 0;
        q.push(root);
        while(q.size()>0)
        {
        
            int size = q.size();
            while(size-->0)
            {
                TreeNode* node = q.front();
                q.pop();
                 if(depth == 1)
                 {
                     ans+=node->val;
                 }
                if(node->left!=nullptr)
                {
                    q.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    q.push(node->right);
                }
            }
                depth--;
        }
        return ans;
    }
};