class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> soln;

        for(int i=0; i < nums.size() -1 ; i++) {
            int a = nums[i];
            if(i>0 && a==nums[i-1]) continue;

            int l=i+1,r=nums.size()-1;

            while(l < r) {
                int sum = a + nums[l] + nums[r];
                if(sum < 0) l++;
                else if(sum>0) r--;
                else {
                    vector<int> temp;
                    temp.push_back(a);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    soln.push_back(temp);
                    l++;
                    while(nums[l] == nums[l-1] && l<r) l++;
                }

            }
        }
        return soln;
    }
};
