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
    int maxDepth(Node* root) {
        if(root == nullptr)
        {
            return 0;
        }
        int lvl = 0;
        queue<Node*> q;
        q.push(root);
        while(q.size()>0)
        {
            int size = q.size();
            lvl++;
            while(size-->0)
            {
                Node* temp = q.front();
                q.pop();
                for(Node* k:temp->children)
                {
                    if(k!=nullptr)
                    {
                        q.push(k);
                    }
                }
            }
        }
        return lvl;
    }
};