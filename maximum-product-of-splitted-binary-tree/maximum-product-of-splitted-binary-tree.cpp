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
    int mod = 1e9+7;
    long long oans = INT_MIN;
    long long tsum = 0;
    long long findmax(TreeNode* root,long long tsum)
    {
        if(root == NULL)
        {
            return 0;
        }
        long long left = findmax(root->left,tsum);
        long long right = findmax(root->right,tsum);
        long long csum = root->val + left + right;
        long long prod = csum*(tsum-csum);
        oans = max(prod,oans);
        return csum;
    }
    
    long long calculateroot(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        long long leftsum = calculateroot(root->left);
        long long rightsum = calculateroot(root->right);
        return root->val+leftsum+rightsum;
    }
    
    int maxProduct(TreeNode* root) {
        tsum = calculateroot(root);
        int k = findmax(root,tsum);
        return oans%mod;
    }
};