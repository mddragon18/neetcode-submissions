class Solution {
public:
    // we'll use a for loop , inside every loop , I'll initialize a new hashmap , as
    // I pass through the string , I'll go linearly using a two pointer approach , 
    // slow pointer would be on the beginning of substring and the fast pointer tracks the
    // matched character , then if we encounter a hashmap collision , we'll update the length
    // of the longest substring
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i=0,j;
        int max_count=0;
        while(i<n) {
            unordered_map<char,bool> hm;
            hm[s[i]]=true;
            int count = 1;
            for(j=i+1;j<n;j++) {
                if(hm[s[j]]) {
                break;
                }
                else {
                    count++;
                    hm[s[j]]=true;
                }

            }
            i++;
            max_count = (count > max_count) ? count : max_count;
        }

        return max_count;
    }
};
