class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> window;
        for(int i=0;i<nums.size();++i){
            if(i>k)
                window.erase(nums[i-k-1]);
            auto pos=window.lower_bound(nums[i]-t);
            if(pos!=window.end() && *pos-nums[i]<=t)
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
