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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
        {
            return ans;
        }
        stack<TreeNode*> all;
        stack<TreeNode*> curr;
        int lvl = 0;
        all.push(root);
        while(all.size()>0)
        {
            int sz = all.size();
            vector<int> temp;
            while(sz--)
            {
                TreeNode* node = all.top();
                all.pop();
                temp.push_back(node->val);
                if(lvl%2 == 0)
                {
                    if(node->left!=NULL)
                    {
                        curr.push(node->left);
                    }
                    if(node->right!=NULL)
                    {
                        curr.push(node->right);
                    }
                }
                else
                {
                     if(node->right!=NULL)
                    {
                        curr.push(node->right);
                    }
                     if(node->left!=NULL)
                    {
                        curr.push(node->left);
                    }
                }
                
            }
            all = curr;
            while(curr.size()>0)
            {
                curr.pop();
            }
            ans.push_back(temp);
            lvl++;
        }
        return ans;
    }
};