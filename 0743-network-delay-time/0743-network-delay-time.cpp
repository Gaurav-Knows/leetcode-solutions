class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> graph(n+1);

        for(auto edge: times){

            graph[edge[0]].push_back({edge[1],edge[2]});

        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> distance (n+1, INT_MAX);

        distance[k]=0;

        pq.push({0,k});

        while (!pq.empty()) {
          auto [time, node] = pq.top();
          pq.pop();

        if (time > distance[node]) {
          continue;
        }

        for (auto edge : graph[node]) {
          int neighbor = edge.first;
          int weight = edge.second;

          int newTime = time + weight;

          if (newTime < distance[neighbor]) {
            distance[neighbor] = newTime;
            pq.push({newTime, neighbor});
        }
      }

    }

    int answer = 0;

    for (int i = 1; i <= n; i++) {
      if (distance[i] == INT_MAX) {
        return -1;
    }

    answer = max(answer, distance[i]);
    }

    return answer;
        
    }

};