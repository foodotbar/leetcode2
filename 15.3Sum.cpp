class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<=2)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;++i){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                vector<int> curr;
                if(nums[i]+nums[j]+nums[k]==0){
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    curr.push_back(nums[k]);
                    ans.push_back(curr);
                    ++j;
                    --k;
                    while(j<k&&nums[j-1]==nums[j])
                        ++j;
                    while(j<k&&nums[k]==nums[k+1])
                        --k;
                }else if(nums[i]+nums[j]+nums[k]<0)
                    ++j;
                else
                    --k;
            }
            while(i<nums.size()-1&&nums[i]==nums[i+1])
                ++i;
        }
        return ans;
    }
};
