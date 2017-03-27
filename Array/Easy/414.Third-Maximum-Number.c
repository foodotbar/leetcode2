int thirdMax(int* nums, int numsSize) {
    long max1, max2, max3;
    int i;
    for (max1 = max2 = max3 = LONG_MIN, i = 0; i < numsSize; i++) {
        if (max3 >= nums[i] || max1 == nums[i] || max2 == nums[i])
            continue;
        max3 = nums[i];
        if (max2 < max3){
            long tmp=max2;
            max2=max3;
            max3=tmp;
        }
        if (max1 < max2){
            long tmp=max1;
            max1=max2;
            max2=tmp;
        }
    }
    return max3 == LONG_MIN ? max1 : max3;
}
