int removeElement(int* nums, int numsSize, int val) {
    int i,j=0,k;
    for(i=0;i<numsSize;i++){
        if(nums[i]!=val){
            nums[j++]=nums[i];
        }
    }
    numsSize=j;
    return j;
}
