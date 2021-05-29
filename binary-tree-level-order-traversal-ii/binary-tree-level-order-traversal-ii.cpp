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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int> > levelOrder;
    if(root != NULL) {
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty()) {
            int n = Q.size();                  // level node count
            vector<int> visit;
            while(n-- > 0) {                   // level traversal 
                TreeNode *p = Q.front();
                Q.pop();
                visit.push_back(p->val);
                if(p->left) Q.push(p->left);
                if(p->right) Q.push(p->right);
            }
            levelOrder.push_back(visit);
         }
     }        
    std::reverse(levelOrder.begin(), levelOrder.end());       
    return levelOrder;
    }
};