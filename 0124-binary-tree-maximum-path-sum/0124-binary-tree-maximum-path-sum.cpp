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
    
    int ans = INT_MIN;

    int maxPathSum(TreeNode* root) {

        find(root);

        return ans;
        
    }

    int find(TreeNode* root){

        if(root==nullptr){
            return 0;
        }

        int left = find(root->left);
        int right = find(root->right);

        left = max(0, left);
        right = max(0, right);

        int currentPath = left + root->val + right;

        ans = max(ans, currentPath);

        return root->val + max(left, right);



    }
};