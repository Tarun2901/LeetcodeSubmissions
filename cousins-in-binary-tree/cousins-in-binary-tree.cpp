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
    bool isCousins(TreeNode* root, int x, int y) {
        map<int,pair<int,int>> m;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(q.size()>0)
        {   
            int size = q.size();
            while(size-->0)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left!= NULL)
                {
                    m[node->left->val] = make_pair(node->val,depth+1);
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    m[node->right->val] = make_pair(node->val,depth+1);
                    q.push(node->right);
                }
            }
           depth++;
        }
     
       if(m[x].first!=m[y].first && m[x].second == m[y].second)
       {
           return true;
       }
        return false;
    }
};