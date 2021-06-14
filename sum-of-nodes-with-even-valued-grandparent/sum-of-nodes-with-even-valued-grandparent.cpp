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
    int sumEvenGrandparent(TreeNode* root) {
           queue<pair<TreeNode*,pair<int,int>>> q;
           q.push({root,{-1,-1}});
            int sum = 0;
        
        while(q.size()>0)
        {
            int size = q.size();
            
            while(size-->0)
            {
                TreeNode* node = q.front().first;
                int par = q.front().second.first;
                int gpar = q.front().second.second;
                q.pop();
                if(gpar%2 == 0)
                {
                    sum+= node->val;
                }
                
                if(node->left!=NULL)
                {
                    q.push({node->left,{node->val,par}});
                }
                if(node->right!=NULL)
                {
                    q.push({node->right,{node->val,par}});
                }
            }
        }
        return sum;
    }
};