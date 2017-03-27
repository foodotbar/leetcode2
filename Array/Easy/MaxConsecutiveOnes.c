int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int MaxConsecutiveOnes=0;
    int i=0;
    int iMaxConsecutiveOnes=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]==1){
            iMaxConsecutiveOnes++;
        }
        else if(nums[i]==0){
                iMaxConsecutiveOnes=0;
        }
        if(iMaxConsecutiveOnes>=MaxConsecutiveOnes){
                MaxConsecutiveOnes=iMaxConsecutiveOnes;
            }
    }
    return MaxConsecutiveOnes;
}
