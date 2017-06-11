/**
 * Note: The returned array must be malloced, assume caller calls free().
 * https://leetcode.com/problems/two-sum/#/description
 * https://leetcode.com/articles/two-sum/
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* ptr = (int*)malloc(2*sizeof(int));
    int i=0,j=0;
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
		ptr[0]=i;
		ptr[1]=j;
            }
        }
    }
    return ptr;
}

/*

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size()<2)
            return ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        for(int i=0;i<nums.size();i++){
            int t=target-nums[i];
            if(m.count(t)&&m[t]>i){
                ans.push_back(i);
                ans.push_back(m[t]);
            }
        }
        return ans;
    }
};

*/
