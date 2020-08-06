/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root){
        if(root==NULL) return NULL;
        root->left = dfs(root->left);
        root-> right = dfs(root->right);
        if(root->left==NULL && root->right==NULL && root->val==0) return NULL;
        else return root;

    }


    TreeNode* pruneTree(TreeNode* root) {
        return dfs( root);
    }
};