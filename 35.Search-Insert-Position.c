int searchInsert(int* nums, int numsSize, int target) {
    int i,j=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]==target)
            j=i;
        else if(nums[i]<target){
            j=i+1;
        }
    }
    return j;
}
