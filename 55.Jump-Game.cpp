class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        for(int reach=0;i<nums.size()&&i<=reach;i++)
            reach=max(i+nums[i],reach);
        return i==nums.size();
    }
};

/*

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last=nums.size()-1,i,j;
        for(i=nums.size()-1;i>=0;i--)
            if(i+nums[i]>=last)
                last=i;
        return last<=0;
    }
};

*/
