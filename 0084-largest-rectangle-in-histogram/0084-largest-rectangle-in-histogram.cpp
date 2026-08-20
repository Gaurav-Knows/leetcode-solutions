class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        stack<int> st;

        for(int i=0;i<heights.size();i++){
            if(st.empty()){
                st.push(i);
            }
            else if(heights[st.top()]>heights[i]){
                while(!st.empty() && heights[st.top()] > heights[i]){
                int rightH=i;
                
                int idx=st.top();
                

                st.pop();

                int leftH = st.empty() ? -1 : st.top();
                int width = rightH - leftH - 1;
                int area = heights[idx] * width;

                maxArea=max(maxArea,area);
                }

                

                



                
                 

            }
            st.push(i);
        }
            while(!st.empty()) {
            int idx = st.top();
            st.pop();

            int leftH = st.empty() ? -1 : st.top();
            int rightH = heights.size();

            int width = rightH - leftH - 1;
            int area = heights[idx] * width;

            maxArea = max(maxArea, area);
        }
            
        
        return maxArea;
        
    }
};