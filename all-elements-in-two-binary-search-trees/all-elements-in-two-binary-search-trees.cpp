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
    vector<int> list1;
    vector<int> list2;
    void inorder1(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder1(root->left);
        list1.push_back(root->val);
        inorder1(root->right);
    }
    void inorder2(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder2(root->left);
        list2.push_back(root->val);
        inorder2(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder1(root1);
        inorder2(root2);
        int n = list1.size();
        int m = list2.size();
        int i = 0;
        int j = 0;
        
        vector<int> ans(n+m,0);
        int k = 0;
        
        while(i<n && j<m)
        {
            if(list1[i]<list2[j])
            {
                ans[k] = list1[i];
                i++;
            }
            else
            {
                ans[k] = list2[j];
                j++;
            }
            k++;
        }
        
        while(i<n)
        {
            ans[k++] = list1[i++];
        }
        while(j<m)
        {
            ans[k++] = list2[j++];
        }
        return ans;
    }
};