class Solution {

    bool binarySearch(vector<int> row, int target, int n) {
        cout<<"Being called "<<target<<endl;
        int lo = 0;
        int high = n-1;
        int mid;
        while(lo <= high) {
            mid = (lo + high)/2;
            if(row[mid]==target) {cout<<"Yes"<<endl;return true;} //not reaching this line
            else if(row[mid]>target) high = mid-1;
            else lo = mid+1;
        }
        return false;
    }



public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(vector<int> row : matrix) {
            int n = row.size();
            if(row[0] <= target && row[n-1]>=target)
                return binarySearch(row,target,n);
            continue;
        }
        return false;
    }
};
