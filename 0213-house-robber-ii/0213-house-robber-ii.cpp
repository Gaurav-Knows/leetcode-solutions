class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n==1){
            return nums[0];
        }

        return max(Robb(nums,0,n-2), Robb(nums,1,n-1));
        
    }

    int Robb(vector<int> & nums, int start, int end){

        vector<int> dp(end-start+1);

        dp[0]= nums[start];

        if (start == end) 
          return nums[start];

        dp[1]= max(dp[0],nums[start+1]);

        for(int i=2; i<dp.size(); i++){
            dp[i]=max(nums[i+start] + dp[i-2],dp[i-1]);
        }

        return dp[dp.size()-1];
    }
};