class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int numsSize=nums.size();
        int ans=0;
        int sum;
        if(numsSize<=3)
            return accumulate(nums.begin(), nums.end(), 0);
        ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<numsSize-2;i++){
            int j=i+1;
            int k=numsSize-1;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<abs(ans-target)){
                    ans=sum;
                    if (ans == target) return ans;
                }
                (sum>target)?k--:j++;
            }
        }
        return ans;
    }
};
