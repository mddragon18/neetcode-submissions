class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        int j=0;
        vector<int> res(0);
        priority_queue<pair<int,int>> max_hp;
        for(j=0; j<k; j++) {
            max_hp.push({nums[j],j});
        }
        res.push_back(max_hp.top().first);
        i++;
        for(j=k; j<nums.size(); j++) {
            //push new element 
            max_hp.push({nums[j],j});
            //check if top is valid otherwise pop
            while(max_hp.top().second < i || max_hp.top().second > j) max_hp.pop();
            //once valid
            res.push_back(max_hp.top().first);
            i++;
        }

        return res;
        

    }
};
