int removeDuplicates(int* nums, int numsSize) {
    int i=0,j=1,k=0,length=1;
    if(numsSize==0)
        return 0;
    for(k=i+1;k<numsSize;k++){
        if(nums[i]==nums[k]){
            continue;
        }
        if(nums[i]!=nums[k]){
            nums[++i]=nums[k];
            length++;
        }
    }
    return length;
}
