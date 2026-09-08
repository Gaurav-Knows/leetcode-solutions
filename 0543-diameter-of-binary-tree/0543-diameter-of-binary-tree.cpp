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
    int diameterOfBinaryTree(TreeNode* root) {

        int maxDiameter=0;

        height(root,maxDiameter);

        return maxDiameter;
        
    }

    int height(TreeNode* root, int& maxDiameter){

        int leftHeight, rightHeight;

        

        if(root==nullptr){
            return 0;
        }

        leftHeight= height(root->left,maxDiameter);

        rightHeight= height(root->right,maxDiameter);

        maxDiameter=max(maxDiameter,leftHeight+rightHeight);

        return 1 + max(leftHeight, rightHeight);

    }
};