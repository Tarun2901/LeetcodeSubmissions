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
    
    int sumOfLeftLeaves(TreeNode* root,bool isLeft = false) {
        if(root == nullptr)
        {
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            return isLeft == true?root->val:0;
        }
        int sum = 0;
        sum+=sumOfLeftLeaves(root->left,true)+sumOfLeftLeaves(root->right,false);
        return sum;
    }
};