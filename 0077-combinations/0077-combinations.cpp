class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(ans,current,n,k,0,1);

        return ans;
        
    }

    void backtrack(vector<vector<int>>& ans,vector<int> &current,int n,int k,int index,int start){
        if(index==k){
            ans.push_back(current);
            return;
        }

        for(int i=start;i<=n;i++){
            current.push_back(i);
            backtrack(ans,current,n,k,index+1,i+1);
            current.pop_back();
        }
    }
};