class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hm;
        for(int x : nums) {
            hm[x]++;
            if(hm[x]>1)
                return x;
        }
    }
};
