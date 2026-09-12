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

    TreeNode* p;
    TreeNode* q;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p=p;
        this->q=q;

        return find(root);

        
        
    }

     TreeNode* find(TreeNode* root){

        if(root==nullptr){
            return nullptr;
        }

        if(root==p||root==q){
            return root;
        }

        TreeNode* left = find(root->left);
        TreeNode* right = find(root->right);

        if(left==nullptr && right==nullptr){
            return nullptr;
        }

        

        if(left==nullptr){
            return right;
        }

        if(right==nullptr){
            return left;
        }

        return root;

        

        

    }
};
