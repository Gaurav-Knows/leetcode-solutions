class Solution {
public:


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(ans,current,nums,0);
        return ans;
        
    }

    void backtrack(vector<vector<int>>& ans,vector<int>& current, vector<int>& nums,int index){
        

        

        if (index == nums.size()){
        ans.push_back(current);
        return;
        }
        
        current.push_back(nums[index]);
        backtrack(ans,current,nums,index+1);
        current.pop_back();


        backtrack(ans,current,nums,index+1);


    }
};