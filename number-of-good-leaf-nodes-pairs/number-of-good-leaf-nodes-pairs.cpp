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
    vector<string> v;
    int countPairs(TreeNode* root, int dist) {
            queue<pair<TreeNode*,string>> q;
            q.push(make_pair(root,""));
        
            while(q.size()>0)
            {
                int size = q.size();
                while(size--)
                {
                TreeNode* node = q.front().first;
                string str = q.front().second;
                q.pop();
                if(node->left == NULL && node->right == NULL)
                {
                    v.push_back(str);
                }
                if(node->left!=NULL)
                {   str.push_back('l');
                    q.push(make_pair(node->left,str));
                    str.pop_back();
                }
                if(node->right!=NULL)
                {
                    str.push_back('r');
                    q.push(make_pair(node->right,str));
                    str.pop_back();
                }
                }
            }
        
      int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string s1=v[i];
            for(int j=i+1;j<n;j++){
                int temp=0;
                string s2=v[j];
                int n=s1.size();
                int m=s2.size();
                bool pos=true;
                for(int k=0;k<max(n,m);k++){
                    if(k<n&&k<m){
                       if(pos&&s1[k]!=s2[k]){
                           temp+=2;
                           pos=false;
                       } 
                        else if(!pos){
                            temp+=2;
                        }
                    }
                    else if(k<n){
                        temp++;
                    }
                    else{
                        temp++;
                    }
                }
                if(temp<=dist){
                    ans++;
                }
            }
        }
        return ans;
    }
};