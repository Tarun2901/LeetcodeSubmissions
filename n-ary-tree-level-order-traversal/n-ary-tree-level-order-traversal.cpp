/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)
        {
            return {};
        }
        queue<Node*> q;
        vector<int> temp;
        q.push(root);
        while(q.size()>0)
        {
            int size = q.size();
            while(size-->0)
            {
                Node* node = q.front();
                temp.push_back(node->val);
                q.pop();
                for(Node* child:node->children)
                {
                    if(child!=nullptr)
                        q.push(child);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};