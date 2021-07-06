/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> clone;
    
    Node* helper(Node* node, unordered_map<Node*, bool>& mp) {
        Node* root = new Node(node->val);
        clone[node]=root;
        mp[node]=true;
        for(Node* n: node->neighbors){
            Node* child;
            if(!mp[n]){
                child=helper(n,mp);
            }
            else{
                child=clone[n];
            }
            root->neighbors.push_back(child);
        }
        return root;
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        unordered_map<Node*, bool> mp;
        return helper(node, mp);
    }
 
};