class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> curr;

        backtrack(s,ans,0,curr);

      

        return ans;
    }
    bool isPalindrome(string &s, int left, int right) {
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
    }

    void backtrack(string &s,vector<vector<string>> &ans, int index,vector<string> &curr){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }


        for(int i=index;i<s.size();i++){
          if(isPalindrome(s,index,i)){
            curr.push_back(s.substr(index, i - index + 1));
            backtrack(s,ans,i+1,curr);
            curr.pop_back();
        }
        }
    }
};