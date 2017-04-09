class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        if(nums.size()<1)
            return ret;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(flag==0)
                    ret[0]=i;
                ++flag;
            }
        }
        if(flag>0)
            ret[1]=ret[0]+flag-1;
        return ret;
    }
};

/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        if(nums.size()<1)
            return ret;
        int i=0,j=nums.size()-1;
        //search for the left one
        while(i<j){
            int mid=(i+j)/2;
            if(nums[mid]<target)
                i=mid+1;
            else
                j=mid;
        }
        if(nums[i]!=target)
            return ret;
        else
            ret[0]=i;
        j=nums.size()-1;
        //search for the right one
        while(i<j){
            int mid=(i+j)/2+1;
            if(nums[mid]>target)
                j=mid-1;
            else
                i=mid;
        }
        ret[1]=j;
        return ret;
    }
};
*/
