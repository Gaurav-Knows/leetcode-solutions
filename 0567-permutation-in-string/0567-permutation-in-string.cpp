class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>needed;
        unordered_map<char,int>window;

        int left=0;
        int right=0;
        
        int matches=0;
        int i=0;
        while(i<s1.size()){
            needed[s1[i]]++;
            i++;
        }

        int required = needed.size();

        while(right<s2.size()){
            window[s2[right]]++;
            
            if(needed.count(s2[right]) &&needed[s2[right]]==window[s2[right]]){
                matches++;
            }

            

            if(right-left+1>s1.size()){
                
                if(needed.count(s2[left]) && needed[s2[left]]==window[s2[left]]){
                matches--;
                
                }
                window[s2[left]]--;
                left++;
            }

            if(matches==required){
                return true;
            }

            right++;
        
        }
        return false;
        
    }
};