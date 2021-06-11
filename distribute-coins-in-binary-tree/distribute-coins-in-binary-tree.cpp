 /* Definition for a binary tree node.
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
    
    int cost = 0;
    
    int travel(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int left = travel(root->left);
        int right = travel(root->right);
        
        cost+= abs(left)+abs(right);
        return left+right+root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        travel(root);
        return cost;
    }
};