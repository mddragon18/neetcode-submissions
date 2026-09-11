class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        int mid,min_el=nums[0];

        while(l <= r) {
            mid = (l+r)/2;
            min_el = min(min_el,nums[mid]);
            if(nums[r] < nums[mid]) l = mid + 1;
            else  r = mid - 1; 
        }

        return min_el;
    }
};
