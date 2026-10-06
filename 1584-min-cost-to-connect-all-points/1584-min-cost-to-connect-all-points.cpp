class Solution {
public:
    vector<int> parent;
    
    int find(int x){

        if(parent[x]==x){
            return x;
        }

        return find(parent[x]);

    }


    int minCostConnectPoints(vector<vector<int>>& points) {



        int n = points.size();

        parent.resize(n);
        
        vector<tuple<int,int,int>> edges;

        


        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int cost = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);

                edges.push_back({cost,i,j});

            }
        }

        for (int i = 1; i < n; i++) {
            parent[i] = i;
        }

        sort(edges.begin(), edges.end());

        int totalCost=0;
        int edgesUsed=0;

        for(auto [cost, u, v] : edges) {

            int a = find(u);
            int b = find(v);

            if(a==b){
                continue;
            }

            parent[b]=a;

            totalCost += cost;
            edgesUsed++;

            if(edgesUsed==n-1){
                break;
            }


        }
        return totalCost;
    }
};