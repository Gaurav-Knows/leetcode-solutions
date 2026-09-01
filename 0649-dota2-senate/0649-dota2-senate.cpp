class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R;
        queue<int> D;

        for(int i = 0; i < senate.size(); i++) {
        if(senate[i] == 'R')
          R.push(i);
        else
          D.push(i);
        }

        while(!R.empty() && !D.empty()){

        if(R.front()<D.front()){
            

            int r=R.front();
            D.pop();
            
            R.pop();

            R.push(r + senate.size());


        }

        else{
            int d=D.front();
            D.pop();
            R.pop();

            D.push(d + senate.size());
        }

    }
    if(R.empty()){
    return "Dire";
    }

    return "Radiant";
        
    }
};