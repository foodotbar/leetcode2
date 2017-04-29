class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.empty()?0:nums[0];
        vector<int> v1=nums,v2=nums;
        v1.erase(v1.begin());
        v2.pop_back();
        return max(robHouse(v1),robHouse(v2));
    }
    int robHouse(vector<int>& nums){
        if(nums.size()<=1)
            return nums.empty()?0:nums[0];
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
