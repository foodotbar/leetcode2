class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int numsSize=nums.size();
        vector<vector<int>> ret;
        if(numsSize<4) 
            return ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<numsSize-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[numsSize-3]+nums[numsSize-2]+nums[numsSize-1]<target) continue;
            for(int j=i+1;j<numsSize-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[numsSize-2]+nums[numsSize-1]<target) continue;
                int left=j+1,right=numsSize-1;
                while(left<right)
                {
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        ret.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return ret;
    }
};
