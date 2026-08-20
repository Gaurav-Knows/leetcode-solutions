class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char ,int>needed;
        unordered_map<char, int>window;

        int minLen = INT_MAX;
        int start = 0;

        int left=0;
        int right=0;
        int matches=0;

        int i=0;


        while(i<t.size()){
            needed[t[i]]++;
            i++;
        } 

        while(right<s.size()){
            window[s[right]]++;

            if(needed.count(s[right])&&needed[s[right]]==window[s[right]]){
               
                matches++;
            }

            while(matches==needed.size()){
                 

                if(needed.count(s[left])&&needed[s[left]]==window[s[left]]){
                matches--;
                }

                if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
                }

                window[s[left]]--;
                left++;

               
                
            }
            right++;

        }
        if (minLen == INT_MAX) {
        return "";
        }

        return s.substr(start, minLen);
        
    }
};