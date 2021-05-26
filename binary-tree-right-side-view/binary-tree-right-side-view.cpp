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
public: vector<int>ans;
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0)
        {
            int size = q.size();
            while(size>0)
            {
                if(size==1)
                {
                    ans.push_back(q.front()->val);
                }
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
                size--;
            }
        }
        return ans;
    }
};