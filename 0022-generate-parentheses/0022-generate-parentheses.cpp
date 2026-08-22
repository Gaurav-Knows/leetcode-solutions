class Solution {
public:
    vector<string> ans;
    string current;
 
    vector<string> generateParenthesis(int n) {
        backtrack(current,0,0,n);

        return ans;
        
    }
    

    

    void backtrack(string& current,int open, int close,int n){

        if (open + close == 2 * n) {
            ans.push_back(current);
            return;
        }
        
    
        

        if(open<n){
            current.push_back('(');
            backtrack(current,open+1,close,n);
            current.pop_back();
        }
        if(close<open){
            current.push_back(')');
            backtrack(current,open,close+1,n);
            current.pop_back();
        }

        
    }
};