int majorityElement(int* nums, int numsSize) {
    int i=0,counter=1,majority=nums[0];
    for(i=1;i<numsSize;i++){
        if(counter==0){
            majority=nums[i];
            counter++;
        }else if(nums[i]==majority)
            counter++;
        else
            counter--;
    }
    return majority;
}
