class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>>graph(n);

        for(auto flight: flights){

            graph[flight[0]].push_back({flight[1],flight[2]});
        }

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        
        

        vector<vector<int>> distance(k + 2, vector<int>(n, INT_MAX));

        pq.push({0,src,0});

        while(!pq.empty()){

            auto[cost,node,stops]=pq.top();
            pq.pop();

            if(stops>k){
                continue;
            }

            for(auto n: graph[node]){

                int neighbor = n.first;
                int weight = n.second;

                int newTime = cost + weight;
                int newStops = stops + 1;

                if (newTime < distance[newStops][neighbor]) {

                    distance[newStops][neighbor] = newTime;
                    pq.push({newTime, neighbor, newStops});
                }




            }
        }

        int answer = INT_MAX;

        for(int flights = 0; flights <= k + 1; flights++){
           answer = min(answer, distance[flights][dst]);
        }

        if(answer == INT_MAX)
           return -1;

        return answer;

        
    }
};