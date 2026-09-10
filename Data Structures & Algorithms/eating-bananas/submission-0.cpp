class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        auto it = max_element(piles.begin(), piles.end());
        int r = *it;
        int res = r;

        while (l <= r) {
            int k = (l + r) / 2;
            int hours = 0;
            for (int p : piles) {
                hours += ceil((double)p / k);
            }
            if (hours <= h) {
                res = min(res, k);
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
