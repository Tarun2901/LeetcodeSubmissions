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
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {   int mx = INT_MIN;
            int size = q.size();
            while(size-->0)
            {
                TreeNode* temp = q.front();
                q.pop();
                mx = max(mx,temp->val);
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
            }
            res.push_back(mx);
        }
        return res;
    }
};