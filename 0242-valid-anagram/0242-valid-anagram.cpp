class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;

        if(s.size()!=t.size()){
            return false;
        }
        else{
            for(int i=0;i<t.size();i++){
                freq1[s[i]]++;
            }
            for(int i=0;i<t.size();i++){
                freq2[t[i]]++;
            }

            
            return (freq1==freq2);
            

        }
        
    }
};