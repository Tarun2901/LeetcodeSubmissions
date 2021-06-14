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

/*


0 - Leaf Node/ Dummy Leaf Node
1 - Node with Camera
2 - Node without Camera but covered by a camera

*/
class Solution {
public:
    
    int count = 0;
    
    int solve(TreeNode* root)
    {
        if(root == NULL)
        {
            return 2;
        }
        int leftans = solve(root->left);
        int rightans = solve(root->right);
        
        if(leftans == 0 || rightans == 0)
        {   //Since one of the children is a leaf node or dummy leaf node and is not covered by a camera then 
            count++;
            return 1;
        }
        if(leftans == 1 || rightans == 1)
        {
            //Node is covered by a camera
            return 2;
        }
        if(leftans == 2 && rightans == 2)
        {   //case of leaf node or dummy leaf node.
            return 0;
        }
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        int ans = solve(root);
        
        if(ans == 0)
        {
            count++;
        }
        return count;
    }
};