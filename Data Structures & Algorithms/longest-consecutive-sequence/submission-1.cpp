class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> fnums=nums;
        sort(fnums.begin(),fnums.end());
        int count=0;
        int longestStreak=0;

        for(int i=0;i<fnums.size();i++) {
            if(i==0) {
                count++;
                continue;
            }
            if(fnums[i]==fnums[i-1]) continue;
            if(fnums[i]==fnums[i-1]+1) count++;
            else {
                longestStreak = (count > longestStreak) ? count:longestStreak;
                count=1;
            }
        }

        return (longestStreak > count)? longestStreak:count;

    }
};
