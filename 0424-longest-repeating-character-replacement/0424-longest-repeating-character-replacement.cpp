class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;

        int maxFreq=0;
        int right=0;
        int left=0;
        int maxLen=0;
        int windowSize=0;

        while(right<s.size()){

            freq[s[right]]++;
            maxFreq=max(maxFreq,freq[s[right]]);

           

            

            while(right-left+1-maxFreq>k){
                freq[s[left]]--;
                left++;
            }

            windowSize=right-left+1;

            maxLen=max(maxLen,windowSize);
            right++;

            
        
    }
    return maxLen;
    }
};