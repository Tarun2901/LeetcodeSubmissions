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
    
    unordered_map<int,int> mp; // subtree sum to its frequency
    vector<int> ans;
    
    int travelandfill(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftsum = travelandfill(root->left);
        int rightsum = travelandfill(root->right);
        int subtreesum = root->val + leftsum + rightsum;
        mp[subtreesum]++;
        return subtreesum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int token = travelandfill(root);
        int mx = INT_MIN;
        for(auto p: mp)
        {
           mx = max(mx,p.second);
        }
        for(auto p:mp)
        {
            if(p.second == mx)
            {
                ans.push_back(p.first);
            }
        }
        
        return ans;
    }
};