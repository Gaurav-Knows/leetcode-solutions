class Solution {
public:
    int findTheWinner(int n, int k) {

        vector<int>win;

        for(int i=1;i<=n;i++){
            win.push_back(i);

        }

        return findW(win,k,0);


        
    }

    int findW(vector<int> & win, int k, int index){

        if(win.size()==1){
            return win[0];
        }

        index = (index + k -1)% win.size();

        win.erase(win.begin()+index);

        return findW(win, k, index);
    }
        
    
};