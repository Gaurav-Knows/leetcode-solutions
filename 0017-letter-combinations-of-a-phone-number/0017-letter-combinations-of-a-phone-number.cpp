class Solution {
public:
    vector<string> ans;
    string current;
    vector<string> letterCombinations(string digits) {
        

        backtrack(digits,0,current);

        return ans;
        
    }

    void backtrack(string digits,int index, string& current){
        vector<string> letters = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        if(index == digits.size()){
            ans.push_back(current);
            return;
        }

        if(index<digits.size()){

        string choices = letters[digits[index] - '0'];

        for (int i = 0; i < choices.size(); i++) {
            current.push_back(choices[i]);
            backtrack(digits,index+1,current);
            current.pop_back();
        }

    }
    }
};