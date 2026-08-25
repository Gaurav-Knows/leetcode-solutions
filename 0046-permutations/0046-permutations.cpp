class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector <int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> curr;

        backtrack(ans,curr,nums,used);

        return ans;
        
    }

    void backtrack(vector<vector <int>> &ans, vector<int> &curr,vector<int> &nums, vector<bool> &used ){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if (used[i])
            continue;

            curr.push_back(nums[i]);
            used[i]=true;

            backtrack(ans,curr,nums,used);

            used[i]=false;
            curr.pop_back();
            
            

        
        }
    }
};