class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> map(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto p: prerequisites){
            map[p[1]].push_back(p[0]);
            indegree[p[0]]++;

        }
        
        queue<int> q;

       for(int i = 0; i < numCourses; i++){
        if(indegree[i]==0){

            q.push(i);
            



        }
       }

       int count = 0;

       while(!(q.empty())){
        int course=q.front();
        q.pop();

        count++;

        for (auto m : map[course]) {
        indegree[m]--;
        

        if (indegree[m] == 0) {
            q.push(m);
        }

       }
       }

       if(count==numCourses){
        return true;
       }

       return false;
        
    }
};