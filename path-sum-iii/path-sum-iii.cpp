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
    
    unordered_map<int,int> mp;
    int count = 0;
    void travelandcount(TreeNode* root,int target,int currsum)
    {   if(root == NULL)
        {
             return;
        }
      
        currsum+=root->val;
        count+=mp[currsum-target];
        mp[currsum]++;
        
        travelandcount(root->left,target,currsum);
        travelandcount(root->right,target,currsum);
        mp[currsum]--;
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        mp[0] = 1;
        travelandcount(root,targetSum,sum);
        return count;
    }
};