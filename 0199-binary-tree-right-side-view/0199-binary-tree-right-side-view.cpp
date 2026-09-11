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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        level(ans,root);

        return ans;
        
        
    }

    void level(vector<int> &ans,TreeNode* root){
        if(root==nullptr){
            return;
        }

        queue<TreeNode *>q;

        q.push(root);

        

        while(!q.empty()){
            int size=q.size();

        for(int i=0;i<size;i++){
            TreeNode* Node=q.front();
            q.pop();

            if(i==size-1){
                ans.push_back(Node->val);
            }

            if (Node->left)
                q.push(Node->left);

            if (Node->right)
                q.push(Node->right);
            
        }

        

        }

    
    }
};