class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.empty()?0:nums[0];
        vector<int> dp={nums[0],max(nums[0],nums[1])};
        for(int i=2;i<nums.size();i++){
            dp.push_back(max(dp[i-1],dp[i-2]+nums[i]));
        }
        return dp.back();
    }
};

/*

class Solution {
public:
    int rob(vector<int>& nums) {
        int a=0,b=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                a+=nums[i];
                a=max(a,b);
            }else{
                b+=nums[i];
                b=max(a,b);
            }
        }
        return max(a,b);
    }
};

*/
