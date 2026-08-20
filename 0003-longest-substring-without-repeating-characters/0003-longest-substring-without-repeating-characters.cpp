class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> f;
        int left=0;
        int right=0;

        int maxLen=0;

        while(right<s.size()){
            if(f.count(s[right])){
                while(f.count(s[right])){
                f.erase(s[left]);
                left++;
                
                }

                f.insert(s[right]);
                right++;

            maxLen=max(maxLen,(int)f.size());
                
            }

            else{
                f.insert(s[right]);
                maxLen=max(maxLen,(int)f.size());
                right++;
            }

            

        }

        return maxLen;
        
    }
};