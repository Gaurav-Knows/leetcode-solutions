class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector <int>> ans;
        vector<int> current;

        backtrack(ans,current,candidates,target,0,0);

        return ans;
        
    }

    void backtrack(vector<vector <int>> &ans, vector<int> &current, vector<int> &candidates,int target,int sum,int start){
        if(sum==target){
            ans.push_back(current);
            return;
        }
        if(sum>target){
            return;
        }

        for(int i=start;i<candidates.size();i++){
            sort(candidates.begin(), candidates.end());
            if (i > start && candidates[i] == candidates[i-1])
            continue;
            current.push_back(candidates[i]);
            
            backtrack(ans,current,candidates,target,sum+candidates[i],i+1);
            current.pop_back();
        }
    }
};