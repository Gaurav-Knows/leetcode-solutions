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
    
    unordered_map<int,int> inMap;
    vector<int> preorder; 

    int preIndex=0;

    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int start=0;
        int end=inorder.size()-1;

        this->preorder = preorder;

        for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
        }

        

        return build(start,end);

        
    }

    

    TreeNode* build(int start,int end){

        if(start>end){
            return nullptr;
        }
        
        

        int rootVal = preorder[preIndex];

        preIndex++;

        TreeNode* root=new TreeNode(rootVal);

        int mid= inMap[rootVal];

        root->left = build(start,mid-1);
        root->right = build(mid+1,end);

        return root;

        

        


    }


};