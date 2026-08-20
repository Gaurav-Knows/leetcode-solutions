class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
    return 0;
}
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
         leftMax[0]=height[0];
        for(int i=1;i<height.size();i++){
           
            leftMax[i]=max(height[i],leftMax[i-1]);
        }

        rightMax[height.size()-1]=height[height.size()-1];

        for(int i=height.size()-2;i>=0;i--){
            

            rightMax[i]=max(height[i],rightMax[i+1]);
        }
        int water = 0;

        for(int i=0;i<height.size();i++){
            water+=min(leftMax[i],rightMax[i])-height[i];
        }

        return water;
        
    }
};