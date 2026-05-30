class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // I'll first make a hashmap of frequencies
        unordered_map<int,int> hm;
        for (int x : nums) 
        hm[x]++;
        // push the hm entries into a max heap 
        priority_queue<pair<int,int>> pq;

        for (auto &[element,count]: hm) {
            pq.push({count,element});
        }
        // extract top k elements
        vector<int> ans;
        for(int i=0;i<k;i++) {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }

        return ans;


    }
};
