int findPairs(int* nums, int numsSize, int k) {
    int i=0;
    int numbers=0;
    int* subnums=nums;
    subnums[0]=nums[0];
    int j=0;
    int m=0;
    int subnumsSize=1;
    int flag=0;
    for(i=1;i<numsSize;i++){
        for(m=0;m<subnumsSize;m++){
            if(nums[i]==subnums[m])
                flag++;
        }
        if(flag){
            if(k==0&&flag==1){
                subnumsSize++;
                j++;
                subnums[j]=nums[i];
            }
        flag=0;
        }else{
            subnumsSize++;
            j++;
            subnums[j]=nums[i];
        }
    }
    for(i=0;i<subnumsSize-1;i++){
        for(j=i+1;j<subnumsSize;j++){
            if(abs(subnums[j]-subnums[i])==k)
                numbers++;
        }
    }
    return numbers;
}
