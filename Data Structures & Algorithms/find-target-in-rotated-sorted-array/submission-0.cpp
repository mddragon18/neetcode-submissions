class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid,cut;

        while(l<r) {
            mid = (l+r)/2;
            if(nums[mid] > nums[r]) l=mid+1;
            else r = mid;
        }

        int result = binarySearch(nums,target,0,l-1);
        if(result!=-1) return result;

        return binarySearch(nums,target,l,nums.size()-1);

    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        int mid;
        while(left <= right) {
            mid = (left+right) / 2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
};
