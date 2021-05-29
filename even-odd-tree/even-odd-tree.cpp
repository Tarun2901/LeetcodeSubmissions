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
    bool isEvenOddTree(TreeNode* root) {
            int lvl = 0;
            queue<TreeNode*> q;
            bool bEven = true;
            q.push(root);
            while(q.size()>0)
            {
                int size = q.size();
    		int prev = bEven ? INT_MIN : INT_MAX;

                while(size-->0)
                {   TreeNode* node = q.front();
                    q.pop();
                if(bEven)
                    {
                        if((node->val%2)==0 || prev>=node->val)
                        {
                            return false;
                        }
                       prev = node->val;
                    }
                 else if(!bEven)
                 {
                     if((node->val%2)==1 || prev<=node->val)
                     {
                         return false;
                     }
                      prev = node->val;
                 }
                 
                 if(node->left!=NULL)
                 {
                     q.push(node->left);
                 }
                 if(node->right!=NULL)
                 {
                     q.push(node->right);
                 }
              
                }
            
                bEven = !bEven;
            }
     
        return true;
    }
};