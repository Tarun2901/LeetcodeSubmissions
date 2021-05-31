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
    
    vector<vector<int>> ans;
    
    static bool compareTo(const pair<int,int>p1,const pair<int,int>p2)
    {
        if(p1.second!=p2.second)
        {
            return p1.second<p2.second;
        }
        else
        {
            return p1.first<p2.first;
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<pair<int,int>>> m; // Vertical level ------- {value,Horizontal Level};
        queue<pair<TreeNode*,int>> q; // Value,Vertical Level
        q.push(make_pair(root,0));
        int hlvl = 0;
        while(q.size()>0)
        {
            int size = q.size();
            while(size>0)
            {
                TreeNode* node = q.front().first;
                int vlvl = q.front().second;
                q.pop();
                m[vlvl].push_back(make_pair(node->val,hlvl));
                if(node->left!=NULL)
                {
                    q.push(make_pair(node->left,vlvl-1));
                }
                if(node->right!=NULL)
                {
                    q.push(make_pair(node->right,vlvl+1));
                }
                size--;
            }
            hlvl++;
        }
        
            for (auto itr : m) {
            vector<pair<int, int>> temp = itr.second;
            sort(temp.begin(), temp.end(), compareTo);
            vector<int> res;
            for (auto i : temp) {
                res.push_back(i.first);
            }
            ans.push_back(res);
            }
        return ans;
    }
};