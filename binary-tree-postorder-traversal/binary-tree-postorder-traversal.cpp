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
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* last = NULL;
        while(!st.empty() || curr)
        {
           if(curr)
           {
               st.push(curr);
               curr = curr->left;
           }
            else
            {
                TreeNode* node = st.top();
                if(node->right && node->right!=last)
                {
                    curr = node->right;
                }
                else
                {
                    ans.push_back(node->val);
                    last = node;
                    st.pop();
                }
            }
        }
        return ans;
    }
};