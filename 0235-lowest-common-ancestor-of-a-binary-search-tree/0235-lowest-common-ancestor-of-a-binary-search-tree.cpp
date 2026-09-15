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

    TreeNode *p;
    TreeNode *q;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        this->p=p;
        this->q=q;
        
        return find(root);
        
    }

    TreeNode* find(TreeNode *root){

        

        if(p->val<root->val && q->val<root->val){
            return find(root->left);
        }

        if(p->val>root->val && q->val>root->val){
            return find(root->right);
        }

        return root;

    }
};