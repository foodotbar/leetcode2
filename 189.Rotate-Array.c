void rotate(int* nums, int numsSize, int k) {
    if(numsSize==0||numsSize==1||k==0)
        return;
    int i=0,j=0,tmp=0;
    for(j=1;j<=k;j++){
        tmp=nums[numsSize-1];
        for(i=numsSize-1;i>0;i--){
            nums[i]=nums[i-1];
        }
        nums[0]=tmp;
    }
    return;
}
