class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxArea=0;
        while(left<right){
            int width=right-left;
            int minH=min(height[left],height[right]);
            int area=width*minH;

            maxArea=max(maxArea,area);

            if(minH==height[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
        
    }
    
};