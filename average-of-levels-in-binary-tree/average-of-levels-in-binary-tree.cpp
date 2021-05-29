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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        vector<double> v;
        
        q.push(root);
        while(!q.empty()) {
            size_t size = q.size();
            double sum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            double average = sum / size;
            v.push_back(average);
        }
        return v;
    }
};