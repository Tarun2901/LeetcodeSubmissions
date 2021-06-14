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
private:
    string ans = "";
    
public:
    
    void findAns(TreeNode* root, string s){
        if(root == NULL) return;
        
        string tmp;
        tmp.push_back(root->val + 'a');
        s = tmp + s;
        
        if(root->left == NULL && root->right == NULL){
            if(ans == "" || ans > s){
                ans = s;
            }
            return;
        }
        findAns(root->left, s);
        findAns(root->right, s);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        ans = "";
        findAns(root, "");
        return ans;
    }
};