class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int numsSize=nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        if(numsSize<=4)
            return ret;
        for(int i=0;i<numsSize-3;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<numsSize-2;){
                int left=j+1;
                int right=numsSize-1;
                while(left<right){
                    vector<int> curr;
                    if(nums[i]+nums[j]+nums[left]+nums[right]==target){
                        curr.push_back(nums[i]);
                        curr.push_back(nums[j]);
                        curr.push_back(nums[left]);
                        curr.push_back(nums[right]);
                        ret.push_back(curr);
                        do{left++;}while(nums[left]=nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right-1]&&left<right);
                    }
                    if(nums[i]+nums[j]+nums[left]+nums[right]>target){
                        --right;
                    }
                    if(nums[i]+nums[j]+nums[left]+nums[right]<target){
                        ++left;
                    }
                }
            }
        }
        return ret;
    }
};
