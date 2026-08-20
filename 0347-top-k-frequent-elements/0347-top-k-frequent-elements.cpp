class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        

        int i=0;

        vector<int> arr;

        while(i<nums.size()){
            map[nums[i]]++;
            i++;
        }
        
        for(int j=0;j<k;j++){
            int maxFreq=0;
            int maxEle=0;

            for(auto p:map){

            
            if(p.second>maxFreq){
                maxFreq=p.second;
                maxEle=p.first;

            }
            }

            arr.push_back(maxEle);

            map.erase(maxEle);


        }

        return arr;
    }
};