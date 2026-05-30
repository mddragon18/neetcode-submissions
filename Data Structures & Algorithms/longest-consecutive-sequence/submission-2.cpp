class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int x : nums) 
        numSet.insert(x);

        int longest=0;
        for(int x:nums) {
            if(!numSet.count(x-1)) {
                int length=0;
                while(numSet.count(x+length)) 
                    length++;
                longest = (longest>=length) ? longest : length;
                
            }
        }

        return longest;

    }
};
