class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //O(n) -- We use an algorith that groups elements based on their freq -- Bucket Sort

        unordered_map<int,int> hm;
        for(int x : nums)
        hm[x]++;

        vector<vector<int>> buckets(nums.size()+1);
        for(auto &[element,count]:hm) {
            buckets[count].push_back(element);
        }
        vector<int> ans;
        for(int i=buckets.size()-1;ans.size()<k && i>=0;i--) {
            for(int x:buckets[i]) {
                ans.push_back(x);
                if(ans.size() == k) break;
            }
        }

        return ans;

    }
};
