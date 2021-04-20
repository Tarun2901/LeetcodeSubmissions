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
    TreeNode*temp=NULL;
bool find(TreeNode*root,int k){
	if(!root) return false;
	if(root->val==k) return true;
	if(root->val<k) return find(root->right,k);
	if(root->val>k) return find(root->left,k);
	return false;
}
bool answer(TreeNode*root,int k){
	if(!root) return false;
	bool op1=answer(root->left,k);
	int num=k-root->val;
	if(num<root->val)
    if(find(temp,num)) return true;
	bool op2=answer(root->right,k);
	if(op1 or op2){
		return true;
	}
	return false;
}
bool findTarget(TreeNode* root, int k){
	temp=root;
	return answer(root,k);
}
};