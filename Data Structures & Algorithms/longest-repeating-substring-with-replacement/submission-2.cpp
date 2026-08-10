class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxLen=0;
        int maxFreq=0;
        unordered_map<char,int> hashmap;
        for(r=0; r<s.length(); r++) {
            hashmap[s[r]]++;
            maxFreq = max(maxFreq,hashmap[s[r]]);

            while(((r-l+1) - maxFreq) > k) {
                hashmap[s[l]]--;
                l++;
            }

            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};
