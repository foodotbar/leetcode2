void moveZeroes(int* nums, int numsSize) {
    int i=0,j=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nums[j++]=nums[i];
        }
    }
    for(i=j;i<numsSize;i++)
        nums[i]=0;
}
