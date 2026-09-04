class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,less<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> ans;

        for (auto point : points) {
            int x= point[0];
            int y=point[1];

            int dist=x*x +y*y;

            pq.push({dist,{x,y}});

            if(pq.size()>k){
                pq.pop();
            }


        }

        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();

        }

        return ans;

        
        
    }
};