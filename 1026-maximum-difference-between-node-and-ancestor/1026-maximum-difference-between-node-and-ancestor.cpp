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
    int ans;
    int maxAncestorDiff(TreeNode* root) {
        find(root,root->val,root->val);

        return ans;
        
    }

    void find(TreeNode* root,int minVal,int maxVal){
        
        if(root==nullptr){
            return;
        }

        int maxDiff=max(abs(root->val-minVal),abs(root->val-maxVal));

        int newMin=min(minVal,root->val);
        int newMax=max(maxVal,root->val);

        find(root->left,newMin,newMax);
        find(root->right,newMin,newMax);

        ans=max(ans,maxDiff);



        
    }
};